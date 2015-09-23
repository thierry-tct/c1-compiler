#include <common.h>
#include <stdlib.h>
#include <string.h>
#include "C.h"

void gen(enum fct x, long y, float z,enum type t){
    if(cx>cxmax){
	printf("program too long\n");
	exit(1);
    }
    code[cx].f=x; 
    code[cx].l=y; 
    switch(t){
    	case _INT:code[cx].v.i=(int)z;break;
    	case _FLOAT:code[cx].v.d=(double)z;break;
    	case _BOOL:code[cx].v.b=(bool)z;break;
    	case _OPC:code[cx].v.op=(enum opc)z;break;
    	default: {printf("\nerror:unmatched type\n");exit(-1);}
    }
    code[cx].t=t;
    cx=cx+1;
}

void listcode(long cx0){	// list code generated for this block
    long i,tmp;
    char __typs[4][5+1];
    strcpy(mnemonic[lit],"lit");
    strcpy(mnemonic[opr],"opr");
    strcpy(mnemonic[lod],"lod");
    strcpy(mnemonic[sto],"sto");
    strcpy(mnemonic[cal],"cal");
    strcpy(mnemonic[Int],"int");
    strcpy(mnemonic[jmp],"jmp");
    strcpy(mnemonic[jpc],"jpc");
    strcpy(mnemonic[lar],"lar");
    strcpy(mnemonic[sar],"sar");
    strcpy(mnemonic[jpe],"jpe");
    strcpy(mnemonic[init],"init");
    strcpy(__typs[_INT],"int");	
    strcpy(__typs[_FLOAT],"float");
    strcpy(__typs[_BOOL],"bool");
    strcpy(__typs[_OPC],"opc");
    for(i=cx0; i<=cx-1; i++){
	printf("%10ld%5s%3ld%5g%7s\n", i, mnemonic[code[i].f], (long)code[i].l, code[i].t==_FLOAT?(float)code[i].v.d:code[i].v.i,__typs[code[i].t]);
    }
	printf("\n");
}

enum type getType(ASTNode node)
{
	ASTNode tmp=node;
	while(tmp->NodeType!=NULL)
		tmp=tmp->NodeType;
	if(tmp->kind != KType)
		{printf("\ntype error 1\n");exit(-1);}
	if(!strcmp(tmp->type,"int"))
		return _INT;
	if(!strcmp(tmp->type,"float"))
		return _FLOAT;
	if(!strcmp(tmp->type,"bool"))
		return _BOOL;
	printf("\ntype error 2\n");exit(-1);
}

enum type getfuncType(ASTNode node)
{
	ASTNode tmp=node;
	while(tmp->NodeType!=NULL)
		tmp=tmp->NodeType;
	if(tmp->kind != KType)
		{printf("\ntype error 1\n");exit(-1);}
	if(!strcmp(tmp->type,"int"))
		return _INT;
	if(!strcmp(tmp->type,"float"))
		return _FLOAT;
	if(!strcmp(tmp->type,"bool"))
		return _BOOL;
	return _INT;
}

void
codeAST(ASTNode node)
{
	long cx1,cx2,cx0,dx,tmp;
	int i;
	int kind ;
	ASTNode Nod;
	static int initiate_val = 0;
	if(!node){//printf("<< NULL >>\n");
		return;}
	kind = node->kind;

	switch (kind) {
	case KProgram:
	case KMultiDecl:
	case KMultiFuncDef:
	{	
		if(kind == KProgram) {
			int cx00,i;
			cx00=cx;gen(jmp,0,0,_INT);
			for(i=0;i<node->num_funcs;i++)
				gen(jmp,0,0,_INT);
			code[cx00].v.i = cx;
			gen(Int,0,(float)node->dx,_INT);
		}
		List list = node->list;
		ListItr itr = newListItr(list, 0);
		while ( hasNext(itr) )  {
			codeAST((ASTNode)nextItem(itr));
		}
		destroyListItr(&itr);
		break;
	}
	case KParamList:
	case KDeclList:
	case KVarDeclList:
	case KArgList:
	{
		List list = node->list;
		ListItr itr = newListItr(list, 0);
		if(hasNext(itr)){
			codeAST((ASTNode)nextItem(itr));
		}
		while ( hasNext(itr) )  {
			codeAST((ASTNode)nextItem(itr));
		}
		destroyListItr(&itr);
		break;
	}
	case KFuncDef:								
	{
		long cx0;
		//listcode(listcode_cx);
		lev++;
		cx0=cx;gen(jmp,0,0,_INT);
		node->func->ident->sym->addr=cx; //printf("<<%d>>\n",node->func->ident->sym->function_link_pos);
		code[node->func->ident->sym->function_link_pos].v.i = cx;
		if(!strcmp(node->func->ident->sym->name,"main"))
			Main_addr = node->func->ident->sym->addr;
		gen(Int,0,node->func->block->dx,_INT);
		gen(init,getfuncType(node->func->type),3,_INT);	//returned value's type
		// initialise variable types
		//codeAST(node->func->ident);
		codeAST(node->func->paramlist);
		codeAST(node->func->block);
		gen(opr,0,ret,_INT); // return
		code[cx0].v.i=cx;
		/*printf("\n");*///listcode(cx0);listcode_cx = cx;
		lev--;
		break;
	}
	case KFuncName:
	{
		break;	
	}
	case KType:
	{
		break;	
	}
	case KConstDecl:
	{
		ListItr itr;
		ASTNode nod;
		itr = newListItr(node->declaration->idlist->list, 0);
		while ( hasNext(itr) )  {
			nod=(ASTNode)nextItem(itr);
			if(nod->kind == KVarName)
			{
				if(nod->sym->dim > 0)
				{
					int siz=1,i;
					for(i=0;i<nod->sym->dim;i++)
						siz*=nod->sym->dimsizes[i];
					for(i=0;i<siz;i++)
						gen(init,getType(nod->sym->symType),nod->sym->addr+i,_INT);
				}
			}
		}
		destroyListItr(&itr);
		break;	
	}
	case KDecl:
	{
		ListItr itr;
		ASTNode nod;
		itr = newListItr(node->declaration->idlist->list, 0);
		while ( hasNext(itr) )  {
			nod=(ASTNode)nextItem(itr);
			if(nod->kind == KVarName)
			{
				int siz=1,i;
				for(i=0;i<nod->sym->dim;i++)
					siz*=nod->sym->dimsizes[i];
				for(i=0;i<siz;i++)
					gen(init,getType(nod->sym->symType),nod->sym->addr+i,_INT);
			}
		}
		destroyListItr(&itr);
		initiate_val=1;
		codeAST(node->declaration->idlist);
		initiate_val=0;
		break;	
	}
	case KTypedefDecl:
	{
		break;	
	}
	case KParam:
	{
		gen(init,getType(node->declaration->idlist->sym->symType),node->declaration->idlist->sym->addr,_INT);
		break;	
	}
	case KVarName:								
	{
		int i,j,siz;
		floating_sym = node->sym;
		if(initiate_val==1){
			if(node->sym->isInitial)
			{
				initiate_val=0;
				if(node->sym->dim==0 ){
					if(node->sym->type ==1){
						codeAST(*(node->sym->val));
						gen(sto,lev-node->sym->lev,node->sym->addr,_INT);
					}
				}
				else
				{
					siz = 1;
					for(i=0;i<node->sym->dim;i++)	
						siz *= node->sym->dimsizes[i];
					for(i=0;i<siz;i++)
					{
						codeAST((node->sym->val)[i]);
						gen(sto,lev-node->sym->lev,node->sym->addr+i,_INT);
					}
				}
			}	
			initiate_val=1;
			break;
		}
		if(lod_now)
		{
			if(node->sym->type == 0){		//constant
				float tmpp = EvalExp(*(node->sym->val));
				gen(lit,0,tmpp,getType(node->sym->symType));
			}
			else
				gen(lod,lev - node->sym->lev,node->sym->addr,getType(node->sym->symType));
		}
		break;	
	}
	case KFuncDecl:
	{
		break;	
	}
	case KArrayDim:								
	{
		List list = node->list;
		ListItr itr = newListItr(list, 0);
		if(listsize(list)>1){
			printf("\nerror: cannot handle multidimension array!\n");exit(-1);
		}
		while ( hasNext(itr) )  {
			codeAST((ASTNode)nextItem(itr));
		}
		destroyListItr(&itr);
		break;	
	}
	case KListInitExp:
	{
		
		break;	
	}
	case KBlock:
	{
		List list = node->list;
		ListItr itr = newListItr(list, 0);
		while ( hasNext(itr) )  {
			codeAST((ASTNode)nextItem(itr));
		}
		destroyListItr(&itr);
		break;	
	}
	case KMultiStmt:
	{
		List list = node->list;
		ListItr itr = newListItr(list, 0);
		while ( hasNext(itr) )  {
			codeAST((ASTNode)nextItem(itr));
		}
		destroyListItr(&itr);
		break;	
	}
	case KStmt:
	{
		codeAST(node->stmt->stat);
		break;	
	}
	case KExpStmt:
	{
		codeAST(node->estmt->exp);
		break;
	}
	case KBreak:
	{
		if(in_while)
		{
			gen(lit,0,0,_INT);
			gen(jmp,0,breakcx,_INT);
		}
		break;	
	}
	case KContinue:
	{
		if(in_while)
		{
			gen(jmp,0,continuecx,_INT);
		}
		break;	
	}
	case KReturn:							
	{
		if(node->retexp){
			codeAST(node->retexp);
			gen(sto,0,3,_INT);
		}
		gen(opr,0,ret,_INT); 	// return
		break;	
	}
	case KIfStmt:
	{
        	codeAST(node->istmt->Ccond);
		cx1=cx;	gen(jpc,0,0,_INT);
        	codeAST(node->istmt->Cstmt);
		code[cx1].v.i=cx;	
		break;	
	}
	case KIfElseStmt:
	{
        	codeAST(node->istmt->Ccond);
		cx1=cx;	gen(jpc,0,0,_INT);
        	codeAST(node->istmt->Cstmt);
		cx2=cx; gen(jmp,0,0,_INT);
		code[cx1].v.i=cx;
        	codeAST(node->istmt->Estmt);
		code[cx2].v.i=cx;
		break;	
	}
	case KWhileStmt:
	{
		bool tmp = in_while;
		cx1=cx;
		continuecx = cx1;
        	codeAST(node->wstmt->Ccond);
		cx2=cx;	gen(jpc,0,0,_INT);
		breakcx = cx2;
		in_while = TRUE;
        	codeAST(node->wstmt->Cstmt);
		gen(jmp,0,cx1,_INT);
		code[cx2].v.i=cx;
		in_while = tmp;
		break;	
	}
	case KInfixExp:
	{
		long cxx;
		codeAST(node->exp->kids[0]);
		if(node->exp->op==OP_ANDAND){
			cxx=cx;gen(jpc,0,0,_INT);gen(Int,0,1,_INT);
		}
		if(node->exp->op==OP_OROR){
			cxx=cx;gen(jpe,0,0,_INT);gen(Int,0,1,_INT);
		}
		codeAST(node->exp->kids[1]);
		switch(node->exp->op)
		{
			case OP_MINUS	: gen(opr,0,minuss,_OPC);break;
			case OP_PLUS	: gen(opr,0,add,_OPC);break;
			case OP_MULT	: gen(opr,0,mult,_OPC);break;
			case OP_DIV	: gen(opr,0,divv,_OPC);break;
			case OP_EQEQ	: gen(opr,0,eq,_OPC);break;
			case OP_NOTEQ	: gen(opr,0,neq,_OPC);break;
			case OP_LT	: gen(opr,0,lt,_OPC);break;
			case OP_GT	: gen(opr,0,gt,_OPC);break;
			case OP_LTEQ	: gen(opr,0,lte,_OPC);break;
			case OP_GTEQ	: gen(opr,0,gte,_OPC);break;
			case OP_ANDAND	: gen(opr,0,andand,_OPC);gen(Int,0,-1,_INT);code[cxx].v.i=cx;gen(Int,0,1,_INT);break;
			case OP_OROR	: gen(opr,0,oror,_OPC);gen(Int,0,-1,_INT);code[cxx].v.i=cx;gen(Int,0,1,_INT);break;
			case OP_MOD	: gen(opr,0,mod,_OPC);break;
			default : printf("wrong op : \n");
		}
		break;	
	}
	case KCommaExp:
	{
		codeAST(node->exp->kids[1]);
		codeAST(node->exp->kids[0]);
		break;	
	}
	case KAssignExp:
	{	bool tmp=lod_now;
		long siz,i;
		Symbol ss=floating_sym;
		codeAST(node->exp->kids[1]);
		lod_now = FALSE;
		floating_sym=NULL;	
		codeAST(node->exp->kids[0]);
		lod_now = tmp;
		if(floating_sym->dim>0){
			siz=1;
			for(i=0;i<floating_sym->dim;i++)
				siz*=floating_sym->dimsizes[i];
			gen(lit,0,siz,_INT);
			gen(sar,lev - floating_sym->lev,floating_sym->addr,_INT);
		}
		else
			gen(sto,lev - floating_sym->lev,floating_sym->addr,_INT);
		floating_sym=ss;
		break;	
	}
	case KUnaryExp:
	{
		codeAST(node->exp->kids[0]);
		if(node->exp->op==OP_MINUS){
	   		gen(opr,0,neg,_OPC);
		}else if(node->exp->op==OP_NOT){
			gen(opr,0,notnot,_OPC);
		}
		break;	
	}
	case KValue:
	{
		gen(lit,0,node->val,getType(node));
		break;	
	}
	case KParenExp:
	{
		codeAST(node->exp->kids[0]);
		break;	
	}
	case KBool:
	{
		gen(lit,0,node->val,getType(node));
		break;	
	}
	case KConstString:				
	{
		is_String=TRUE;
		if(string_num>=MAX_STRING_NUM){
			printf("\nerror: max number of constant string reached!\n");exit(-1);
		}
		else
		{
			gen(lit,0,string_num,_INT);
			lesstrings[string_num] = node->str;
			string_num++;
		}
		break;	
	}
	case KArrayAccess:						
	{
		long i,siz,ltmp=lod_now;
		Symbol stmp=floating_sym,ss;
		lod_now = FALSE;
		codeAST(node->arrayaccess->id);
		ss=floating_sym;
		lod_now = TRUE;
		codeAST(node->arrayaccess->dim);
		lod_now = ltmp;
		floating_sym = ss;
		if(ltmp){
			siz=1;
			for(i=0;i<floating_sym->dim;i++)
				siz*=floating_sym->dimsizes[i];
			gen(lit,0,siz,_INT);
			gen(lar,lev - floating_sym->lev,floating_sym->addr,_INT);
		}
		if(stmp!=NULL)
			floating_sym = stmp;
		break;	
	}
	case KCallStmt:							
	{
		long tmp,siz;
		//codeAST(node->cstmt->ident);
		tmp=node->cstmt->ident->sym->function_link_pos;
		siz=listsize(node->cstmt->params->list);
		gen(Int,0,4,_INT);			//regs + returned value
		codeAST(node->cstmt->params);		//push params	
		gen(Int,0,-(4+siz),_INT);
		gen(cal,0,tmp,_INT);
		break;	
	}
	case KWrite:
	{
		if(node->cstmt->params != NULL){
			is_String = FALSE;
			codeAST(node->cstmt->params);
			if(is_String){
				gen(opr,_INT,writes,_INT);
				is_String = FALSE;
			}
			else
				gen(opr,_INT,writee,_INT);
		}
		break;	
	}
	case KRead:
	{
		if(node->cstmt->params == NULL){			
			break;
		}
		bool tmp=lod_now;
		long siz,i,cx00;
		Symbol ss=floating_sym;
		lod_now = FALSE;
		floating_sym=NULL;
		cx00=cx;gen(opr,0,readd,_OPC);	
		codeAST(node->cstmt->params);
		lod_now = tmp;
		code[cx00].l=getType(floating_sym->symType);
		if(floating_sym->dim>0){
			siz=1;
			for(i=0;i<floating_sym->dim;i++)
				siz*=floating_sym->dimsizes[i];
			gen(lit,0,siz,_INT);
			gen(sar,lev - floating_sym->lev,floating_sym->addr,_INT);
		}
		else
			gen(sto,lev - floating_sym->lev,floating_sym->addr,_INT);
		floating_sym=ss;
		break;	
	}
	case KPrimary:
	{
		codeAST(node->exp->kids[0]);
		break;	
	}
	default:
		printf("Unhandled ASTNode kind!\n");
	}
}

#ifdef BINARYCODE
void binarycode(ASTNode root){
    cx=0;lev=0;
    printf("\n");
    codeAST(root);
    if(Main_addr<0){
	printf("\nerror: the program dosn't have main function\n");
	return;
    }
    else{
	gen(cal,0,Main_addr,_INT);listcode(cx-1);
    }
    listcode(0);
    FILE * bin_file=fopen("bincode","wb");
    long tmp,i;
    char buf;
    for(i=0; i<=cx-1; i++){
    	fwrite((char *)(&code[i]),sizeof(char),sizeof(instruction),bin_file);
    }
    buf=0xff;
    for(i=0;i<sizeof(instruction);i++)
    	fwrite(&buf,sizeof(char),1,bin_file);			//instriction data separator
    buf=0;
    for(i=0; i<string_num; i++){
	fprintf(bin_file,"%s", lesstrings[i]);
    	fwrite(&buf,sizeof(char),1,bin_file);     //zero final
    }
    fclose(bin_file);
}
#endif

