/*
 * TODO Functions of Abstract Syntax Tree
 * Author: Thierry (thierry@ustc.edu.cn)
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

char *opname[]={
#undef opxx
#define opxx(a, b) b,
#include "op.h"
	"Undefined Op"
};

#define true 1
#define false 0

ASTTree newAST()
{
	ASTTree new;
	NEW0(new);
	return new;
}

Loc setLoc(ASTNode node, Loc loc)//fline, int fcol, int lline, int lcol)
{
	if (node->loc == NULL )
		NEW0(node->loc);
	node->loc->first_line = loc->first_line;
	node->loc->first_column = loc->first_column;
	node->loc->last_line = loc->last_line;
	node->loc->last_column = loc->last_column;
	return node->loc;
}

ASTNode newProgram()
{
	ASTNode new;
	NEW0(new);
	new->kind = KProgram;
	new->list = newList();
	return new;
}

ASTNode newMultiDeclaration()
{
	ASTNode new;
	NEW0(new);
	new->kind = KMultiDecl;
	new->list = newList();
	return new;
}

ASTNode newMultiFuncDef()
{
	ASTNode new;
	NEW0(new);
	new->kind = KMultiFuncDef;
	new->list = newList();
	return new;
}

ASTNode newFuncDef(ASTNode type, ASTNode decl, ASTNode bloc)
{
	ASTNode new;
	NEW0(new);
	new->kind = KFuncDef;
	Func newfunc;
	NEW0(newfunc);
	newfunc->type = type;
	decl->kind = KFuncName;
	newfunc->ident = decl;
	newfunc->paramlist = (decl->sym->paramlists)? decl->sym->paramlists : newParamList();
	newfunc->block = bloc;
	new->func = newfunc;
	return new;
}

ASTNode newFuncName(Table ptab, char *name)
{
	ASTNode new;
	NEW0(new);
	new->kind = KFuncName;
	new->sym = getSym(ptab, name, 3);
	new->sym->type = 3;
	return new;
}

ASTNode newType(char *name)
{
	ASTNode new;
	NEW0(new);
	new->kind = KType;
	new->type = (char *)name;
	new->type0_const1_typedef2 = 0;
	new->NodeType = NULL;
	return new;
}

ASTNode newParamList()
{
	ASTNode new;
	NEW0(new);
	new->kind = KParamList;
	new->list = newList();
	return new;
}

ASTNode newConstDeclaration(Table ptab, ASTNode type, ASTNode idlist)
{
	ASTNode nod;
	ListItr itr;
	ASTNode new;
	NEW0(new);
	new->kind = KConstDecl;
	Declaration newdecl;
	NEW0(newdecl);
	newdecl->type = type;
	newdecl->idlist = idlist;
	itr = newListItr(idlist->list, 0);
	while ( hasNext(itr) )  {
		nod=(ASTNode)nextItem(itr);
		if(nod->kind == KVarName)
		{
			if(!nod->sym->isInitial)
				{printf("\nerror: uninitialized constant!\n");exit(-1);}
			nod->sym->type = 0;		//becomes const
			if(nod->sym->dim > 0)
			{
				int siz=1,i;
				for(i=0;i<nod->sym->dim;i++)
					siz*=nod->sym->dimsizes[i];
				nod->sym->addr = ptab->dx;
				ptab->dx = ptab->dx + siz;	//increase the table's dx
				nod->sym->lev = ptab->lev;
			}
		}
	}
	destroyListItr(&itr);
	new->declaration = newdecl;
	return new;
}

ASTNode newDeclaration(Table ptab, ASTNode type, ASTNode idlist)
{
	ASTNode nod;
	ListItr itr;
	ASTNode new;
	NEW0(new);
	new->kind = KDecl;
	Declaration newdecl;
	NEW0(newdecl);
	newdecl->type = type;
	newdecl->idlist = idlist;
	itr = newListItr(idlist->list, 0);
	while ( hasNext(itr) )  {
		nod=(ASTNode)nextItem(itr);
		if(nod->kind == KVarName)
		{
			int siz=1,i;
			for(i=0;i<nod->sym->dim;i++)
				siz*=nod->sym->dimsizes[i];
			nod->sym->type = 1;		//becomes var
			nod->sym->addr = ptab->dx;
			ptab->dx = ptab->dx + siz;	//increase the table's dx
			nod->sym->lev = ptab->lev;
		}
	}
	destroyListItr(&itr);
	new->declaration = newdecl;
	return new;
}

ASTNode newTypedefDeclaration(ASTNode type, ASTNode idlist)
{
	ASTNode nod;
	ListItr itr;
	ASTNode new;
	NEW0(new);
	new->kind = KTypedefDecl;
	Declaration newdecl;
	NEW0(newdecl);
	newdecl->type = type;
	newdecl->idlist = idlist;
	newdecl->idlist = idlist;
	itr = newListItr(idlist->list, 0);
	while ( hasNext(itr) )  {
		nod=(ASTNode)nextItem(itr);
		if(nod->kind == KVarName)
			nod->sym->type = 2;		//becomes typedef type
	}
	destroyListItr(&itr);
	new->declaration = newdecl;
	return new;
}

ASTNode newDeclList()
{
	ASTNode new;
	NEW0(new);
	new->kind = KDeclList;
	new->list = newList();
	return new;
}

ASTNode newVarDeclList()
{
	ASTNode new;
	NEW0(new);
	new->kind = KVarDeclList;
	new->list = newList();
	return new;
}

ASTNode newParam(ASTNode type, ASTNode vname)
{
	ASTNode new;
	NEW0(new);
	new->kind = KParam;
	Declaration newdecl;
	NEW0(newdecl);
	newdecl->type = type;
	newdecl->idlist = vname;
	new->declaration = newdecl;
	return new;
}

ASTNode newVarName(Table ptab, char *name)
{
	ASTNode new;
	NEW0(new);
	new->kind = KVarName;
	new->sym = getSym(ptab, name, 1);
	return new;
}

ASTNode newFuncDecl(Table ptab, char *name, ASTNode paramlists)
{
	ASTNode new;
	NEW0(new);
	new->kind = KFuncDecl;
	new->sym = getSym(ptab, name, 3);
	new->sym->paramlists = paramlists;
	new->sym->type = 3;
	return new;
}

ASTNode newArrayDim()
{
	ASTNode new;
	NEW0(new);
	new->kind = KArrayDim;
	new->list = newList();
	return new;
}

ASTNode newListInitExp()
{
    	ASTNode new;
	NEW0(new);
	new->kind = KListInitExp;
	new->list = newList();
	return new;	
}

ASTNode newBlock()
{
	ASTNode new;
	NEW0(new);
	new->kind = KBlock;
	new->list = newList();
	return new;
}

ASTNode newMultiStmt()
{
	ASTNode new;
	NEW0(new);
	new->kind = KMultiStmt;
	new->list = newList();
	return new;
}

ASTNode newStmt(ASTNode nod)
{
	ASTNode new;
	NEW0(new);
	new->kind = KStmt;
	Stmt newstmt;
	NEW0(newstmt);
	new->stmt = newstmt;
	newstmt->stat = nod;
	return new;
}

ASTNode newExpStmt(ASTNode exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KExpStmt;
	ExpStmt newstmt;
	NEW0(newstmt);
	new->estmt = newstmt;
	newstmt->exp = exp;
	return new;
}

void destroyExpStmt(ExpStmt *pnode)
{
	ExpStmt node = *pnode;
	destroyAST(&node->exp);
	free(node);
	*pnode = NULL;
}

ASTNode newBreak()
{
	ASTNode new;
	NEW0(new);
	new->kind = KBreak;
	return new;
}

ASTNode newContinue()
{
	ASTNode new;
	NEW0(new);
	new->kind = KContinue;
	return new;
}

ASTNode newReturn(ASTNode exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KReturn;
	new->retexp = exp;
	return new;
}

ASTNode newIfStmt(ASTNode cond, ASTNode stmts)
{
	ASTNode new;
	NEW0(new);
	new->kind = KIfStmt;
	IfStmt newstmt;
	NEW0(newstmt);
	newstmt->Ccond = cond;
	newstmt->Cstmt = stmts;
	new->istmt = newstmt;
	return new;
}

ASTNode newIfElseStmt(ASTNode cond, ASTNode stmts1, ASTNode stmts2)
{
	ASTNode new;
	NEW0(new);
	new->kind = KIfElseStmt;
	IfStmt newstmt;
	NEW0(newstmt);
	newstmt->Ccond = cond;
	newstmt->Cstmt = stmts1;
	newstmt->Estmt = stmts2;
	new->istmt = newstmt;
	return new;
}

ASTNode newWhileStmt(ASTNode cond, ASTNode stmts)
{
	ASTNode new;
	NEW0(new);
	new->kind = KWhileStmt;
	WhileStmt newstmt;
	NEW0(newstmt);
	newstmt->Ccond = cond;
	newstmt->Cstmt = stmts;
	new->wstmt = newstmt;
	return new;
}

ASTNode newInfixExp(int op, ASTNode left, ASTNode right)
{
	ASTNode new;
	NEW0(new);
	new->kind = KInfixExp;
	Exp newexp;
	NEW0(newexp);
	newexp->op = op;
	newexp->kids[0] = left;
	newexp->kids[1] = right;
	if(left->exp->isconst && right->exp->isconst)
	{
		switch(op)
		{
			case OP_PLUS:{newexp->val=left->exp->val + right->exp->val;break;}
			case OP_MINUS:{newexp->val=left->exp->val - right->exp->val;break;}
			case OP_MULT:{newexp->val=left->exp->val * right->exp->val;break;}
			case OP_DIV:{newexp->val=left->exp->val / right->exp->val;break;}
			case OP_LT:{newexp->val=(left->exp->val < right->exp->val);break;}
			case OP_GT:{newexp->val=(left->exp->val > right->exp->val);break;}
			case OP_GTEQ:{newexp->val=(left->exp->val >= right->exp->val);break;}
			case OP_LTEQ:{newexp->val=(left->exp->val <= right->exp->val);break;}
			case OP_EQEQ:{newexp->val=(left->exp->val == right->exp->val);break;}
			case OP_NOTEQ:{newexp->val=(left->exp->val != right->exp->val);break;}
			case OP_ANDAND:{newexp->val=(left->exp->val && right->exp->val);break;}
			case OP_OROR:{newexp->val=(left->exp->val || right->exp->val);break;}
			case OP_MOD:{newexp->val=((int)left->exp->val % (int)right->exp->val);break;}
		}
		newexp->isconst = true;
	}
	else 
		newexp->isconst = false;
	new->exp = newexp;
	return new;
}

ASTNode newCommaExp(ASTNode left, ASTNode right)
{
	ASTNode new;
	NEW0(new);
	new->kind = KCommaExp;
	Exp newexp;
	NEW0(newexp);
	newexp->kids[0] = left;
	newexp->kids[1] = right;
	newexp->isconst = left->exp->isconst;
	newexp->val = left->exp->val;
	new->exp = newexp;
	return new;
}

ASTNode newAssignment(int op, ASTNode left, ASTNode right)
{
	ASTNode new;
	NEW0(new);
	new->kind = KAssignExp;
	Exp newexp;
	NEW0(newexp);
	newexp->op = op;
	newexp->kids[0] = left;
	newexp->kids[1] = right;
	newexp->isconst = right->exp->isconst;
	newexp->val = right->exp->val;
	new->exp = newexp;
	return new;
}

ASTNode newUnaryExp(int op, ASTNode exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KUnaryExp;
	Exp newexp;
	NEW0(newexp);
	newexp->op = op;
	newexp->kids[0] = exp;
	if(exp->exp->isconst)
	{
		switch(op)
		{
			case OP_PLUS:{newexp->val=exp->exp->val;break;}
			case OP_MINUS:{newexp->val=-exp->exp->val;break;}
			case OP_NOT:{newexp->val=!exp->exp->val;break;}
		}
	}
	newexp->isconst = exp->exp->isconst;
	new->exp = newexp;
	return new;
}

ASTNode newgetVarName(Table ptab, char *name)
{
	ASTNode new;
	NEW0(new);
	new->kind = KVarName;
	new->sym = lookup(ptab, name, 1);
	if(!new->sym) {printf("\nerror:%s undeclared in this scope\n",name);exit(-1);}
	return new;
}

ASTNode newgetFuncName(Table ptab, char *name)
{
	ASTNode new;
	NEW0(new);
	new->kind = KFuncName;
	new->sym = lookup(ptab, name, 3);
	if(!new->sym) {printf("\nerror:%s undefined and undeclared in this scope\n",name);exit(-1);}
	return new;
}

ASTNode newNumber(float value)
{
	ASTNode new;
	NEW0(new);
	new->kind = KValue;
	new->val = value;
	new->NodeType = newType("int");
	return new;
}

ASTNode newParenExp(ASTNode exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KParenExp;
	Exp newexp;
	NEW0(newexp);
	newexp->op = -1;
	newexp->kids[0] = exp;
	new->exp = newexp;
	return new;
}

ASTNode newBool(int val)
{
	ASTNode new;
	NEW0(new);
	new->kind = KBool;
	new->val = val;
	new->NodeType =newType("bool");
	return new;
}		

ASTNode newConstString(char *str)
{
	ASTNode new;
	NEW0(new);
	new->kind = KConstString;
	new->str = str;
	return new;
}

ASTNode newArrayAccess(ASTNode id_nod, ASTNode pos_dim)
{
	ASTNode new;
	NEW0(new);
	new->kind = KArrayAccess;
	ArrayAccess newdim;
	NEW0(newdim);
	newdim->id = id_nod;
	newdim->dim = pos_dim;
	new->arrayaccess = newdim;
	return new;
}

ASTNode newCall(ASTNode name, ASTNode params)
{
	ASTNode new;
	NEW0(new);
	new->kind = KCallStmt;
	CallStmt newstmt;
	NEW0(newstmt);
	new->cstmt = newstmt;
	newstmt->ident = name;
	newstmt->params = params;
	return new;
}

ASTNode newWrite(ASTNode params)
{
	ASTNode new;
	NEW0(new);
	new->kind = KWrite;
	CallStmt newstmt;
	NEW0(newstmt);
	new->cstmt = newstmt;
	newstmt->ident = NULL;
	newstmt->params = params;
	return new;
}

ASTNode newRead(ASTNode params)
{
	ASTNode new;
	NEW0(new);
	new->kind = KRead;
	CallStmt newstmt;
	NEW0(newstmt);
	new->cstmt = newstmt;
	newstmt->ident = NULL;
	newstmt->params = params;
	return new;
}

ASTNode newArgList()
{
	ASTNode new;
	NEW0(new);
	new->kind = KArgList;
	new->list = newList();
	return new;
}

ASTNode newPrimary(ASTNode prim)
{
	ASTNode new;
	NEW0(new);
	new->kind = KPrimary;
	Exp newprim;
	NEW0(newprim);
	new->exp = newprim;
	newprim->kids[0] = prim;
	switch(prim->kind)
	{
		case KValue: { newprim->isconst = true; newprim->val = prim->val;break;}
		case KParenExp: { newprim->isconst = prim->exp->isconst; newprim->val = prim->exp->val;break;}
		case KBool: { newprim->isconst = true; newprim->val = prim->val;break;}
		case KVarName:
			{ 
				if(prim->sym->type==0)		//is const
				{	
					newprim->isconst = true; 
					newprim->val = (*(prim->sym->val))->exp->val;
				}
				else	
					newprim->isconst = false; 
				break;
			}
		case KArrayAccess:
			{
				newprim->isconst = (prim->arrayaccess->id->sym->type == 0)? true:false;
				if(newprim->isconst)
				{
					ListItr itr = newListItr(prim->arrayaccess->dim->list, 0);
					int i=1,pos=((ASTNode)nextItem(itr))->val;
					while ( hasNext(itr) && i<prim->arrayaccess->id->sym->dim )
					{
						pos*=prim->arrayaccess->id->sym->dimsizes[i];
						pos+=((ASTNode)nextItem(itr))->val;
						i++;
					}
					destroyListItr(&itr);
					newprim->val = prim->arrayaccess->id->sym->val[pos]->val;
				}
				break;
			}
		default : newprim->isconst = false;break;
	}
	return new;
}

void    setListType(List list,ASTNode type)
{
	ASTNode nod;
	ListItr itr = newListItr(list, 0);
	while ( hasNext(itr) )  {
		nod=(ASTNode)nextItem(itr);
		nod->NodeType = type;
		nod->sym->symType = type;
	}
	destroyListItr(&itr);
}

void    setRenameListType(List list,ASTNode type)
{
	ASTNode nod;
	ListItr itr = newListItr(list, 0);
	while ( hasNext(itr) )  {
		nod=(ASTNode)nextItem(itr);
		nod->NodeType = type;
		nod->sym->type = 2;	//type : 0=const,1=int,2=typedef,3=procedure
		nod->sym->symType = type;
	}
	destroyListItr(&itr);
}

int    forsetinitval(Table ptab,ASTNode var, ASTNode values ,int cur, int pos)
{
	static ASTNode prev=NULL;
	int i;
	ListItr itr = newListItr(values->list, 0);
	if(cur == var->sym->dim - 1)
	{
		for(i=0;i<var->sym->dimsizes[cur];i++)
		{
			if(hasNext(itr))
				prev = (ASTNode)nextItem(itr);
			else{
				printf("\nerror:initialization should be same size with array\n");exit(-1);
			}
			var->sym->val[pos++] = prev; 
			if(prev)
				var->sym->Init_is_const = prev->exp->isconst;     
		}
	}
	else
	{
		for(i=0;i<var->sym->dimsizes[cur];i++)
		{
			if(hasNext(itr)){
				printf("\nerror:initialization should be same size with array\n");exit(-1);
			}
			pos = forsetinitval(ptab,var,(ASTNode)nextItem(itr) ,cur+1, pos);
		}
	}
	destroyListItr(&itr);
	return pos;
}
void    SetInitialValue(Table ptab,ASTNode var, ASTNode values)
{
	var->sym->isInitial = true;
	if(var->sym->dim == 0)		//not an array
	{
		*(var->sym->val) = values;
		var->sym->Init_is_const = values->exp->isconst;
	}
	else
		forsetinitval(ptab,var,values ,0, 0);
}
void    SetArrayDim(Table ptab,ASTNode var, ASTNode arraydim)
{
	int i,vectsiz;
	var->sym->dim = listsize(arraydim->list);
	if(var->sym->dim == 0)
	{
		NEW0(var->sym->val);
		return;
	}
	var->sym->dimsizes = (int *)malloc(var->sym->dim * sizeof (int));
	ListItr itr = newListItr(arraydim->list, 0);
	i=0;vectsiz=1;
	while ( hasNext(itr) )  { 
		var->sym->dimsizes[i] = ((ASTNode)nextItem(itr))->val;
		if(var->sym->dimsizes[i] <= 0)
		{	printf("\nerror : negative or null array size not allowed : set to 1\n");exit(-1);
			var->sym->dimsizes[i]=1;
		}
		vectsiz *= var->sym->dimsizes[i];
		i++;
	}
	destroyListItr(&itr);
	var->sym->val = (ASTNode *)malloc(vectsiz * sizeof(ASTNode));
	
}

float    EvalExp(ASTNode const_expr)
{
	if(const_expr->exp->isconst)
	{
		return const_expr->exp->val;
	}
	else
	{
		printf("\nexit(-1);} : the expression is not constant (array dim)\n");exit(-1);
		return 1;
	}
}

Symbol 	type_exist_sym(Table ptab, char *name)
{
	return lookup(ptab, name, 2);
}

void
destroyAST(ASTNode *pnode)
{
    	if(!pnode)
        	return;
	ASTNode node = *pnode;
	int kind = node->kind;

	switch (kind) {
	case KValue:
	case KVarName:
	case KFuncName:
		break;
	default:
		{printf("Unhandled ASTNode kind!\n");exit(-1);}
	}
	free(node);
	*pnode = NULL;
}

void    dumpAST(ASTNode node)
{
	static int print_val = 0;
	int i;
	int kind;
	if(!node){//printf("<< NULL >>\n");
		return;}
	kind = node->kind;

	switch (kind) {
	case KProgram:
	case KMultiDecl:
	case KMultiFuncDef:
	{
		List list = node->list;
		ListItr itr = newListItr(list, 0);
		while ( hasNext(itr) )  {
			dumpAST((ASTNode)nextItem(itr));
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
			dumpAST((ASTNode)nextItem(itr));
		}
		while ( hasNext(itr) )  {
			printf(",");
			dumpAST((ASTNode)nextItem(itr));
		}
		destroyListItr(&itr);
		break;
	}
	case KFuncDef:
	{
		printf("\n");
		dumpAST(node->func->type);
		printf(" ");
		dumpAST(node->func->ident);
		printf("(");
		dumpAST(node->func->paramlist);
		printf(")");
		dumpAST(node->func->block);
		break;
	}
	case KFuncName:
	{
		printf("%s", node->sym->name);
		break;	
	}
	case KType:
	{
		printf("%s", node->type);
		break;	
	}
	case KConstDecl:
	{
		printf("const ");
		dumpAST(node->declaration->type);
		printf(" ");
		print_val=1;
		dumpAST(node->declaration->idlist);
		printf(";\n");
		print_val=0;
		break;	
	}
	case KDecl:
	{
		dumpAST(node->declaration->type);
		printf(" ");
		print_val=1;
		dumpAST(node->declaration->idlist);
		printf(";\n");
		print_val=0;
		break;	
	}
	case KTypedefDecl:
	{
		printf("typedef ");
		dumpAST(node->declaration->type);
		printf(" ");
		dumpAST(node->declaration->idlist);
		printf(";\n");
		break;	
	}
	case KParam:
	{
		dumpAST(node->declaration->type);
		printf(" ");
		dumpAST(node->declaration->idlist);
		break;	
	}
	case KVarName:
	{
		int i,j,siz;
		printf("%s", node->sym->name);
		if(print_val==1){
			for(i=0;i<node->sym->dim;i++)
				printf("[%d]",node->sym->dimsizes[i]);
			if(node->sym->isInitial)
			{
				printf(" = ");
				print_val=0;
				if(node->sym->dim==0)
					dumpAST(*(node->sym->val));
				else
				{
					siz = 1;
					for(i=0;i<node->sym->dim;i++)	
						siz *= node->sym->dimsizes[i];
					printf("{");
					siz--;
					for(i=0;i<siz;i++)
					{
						dumpAST((node->sym->val)[i]);
						printf(",");
					}
					dumpAST((node->sym->val)[siz]);
					printf("}");
				}
			}	
			print_val=1;
		}
		break;	
	}
	case KFuncDecl:
	{
		printf("%s", node->sym->name);
		printf("()");
		break;	
	}
	case KArrayDim:
	{
		List list = node->list;
		ListItr itr = newListItr(list, 0);
		while ( hasNext(itr) )  {
			printf("[");
			dumpAST((ASTNode)nextItem(itr));
			printf("]");
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
		printf("{\n");
		List list = node->list;
		ListItr itr = newListItr(list, 0);
		while ( hasNext(itr) )  {
			dumpAST((ASTNode)nextItem(itr));
		}
		destroyListItr(&itr);
		printf("}");
		break;	
	}
	case KMultiStmt:
	{
		List list = node->list;
		ListItr itr = newListItr(list, 0);
		while ( hasNext(itr) )  {
			dumpAST((ASTNode)nextItem(itr));
		}
		destroyListItr(&itr);
		break;	
	}
	case KStmt:
	{
		dumpAST(node->stmt->stat);
		printf("\n");
		break;	
	}
	case KExpStmt:
	{
		dumpAST(node->estmt->exp);
		printf(";");
		break;
	}
	case KBreak:
	{
		printf("break;");
		break;	
	}
	case KContinue:
	{
		printf("continue;");
		break;	
	}
	case KReturn:
	{
		printf("return ");
		dumpAST(node->retexp);
		printf(" ;");
		break;	
	}
	case KIfStmt:
	{
		printf("if(");
        	dumpAST(node->istmt->Ccond);
        	printf(")");
        	dumpAST(node->istmt->Cstmt);
        	//printf("}");
		break;	
	}
	case KIfElseStmt:
	{
		printf("if(");
        	dumpAST(node->istmt->Ccond);
        	printf(")");
        	dumpAST(node->istmt->Cstmt);
        	//printf("} ");
		printf("else ");
        	dumpAST(node->istmt->Estmt);
		//printf("}");
		break;	
	}
	case KWhileStmt:
	{
		printf("while(");
        	dumpAST(node->wstmt->Ccond);
       		printf(")");
        	dumpAST(node->wstmt->Cstmt);
        	//printf("}");
		break;	
	}
	case KInfixExp:
	{
		dumpAST(node->exp->kids[0]);
		printf("%s", opname[node->exp->op]);
		dumpAST(node->exp->kids[1]);
		break;	
	}
	case KCommaExp:
	{
		dumpAST(node->exp->kids[0]);
		printf(",");
		dumpAST(node->exp->kids[1]);
		break;	
	}
	case KAssignExp:
	{
		dumpAST(node->exp->kids[0]);
		printf("%s", opname[node->exp->op]);
		dumpAST(node->exp->kids[1]);
		//printf(";");
		break;	
	}
	case KUnaryExp:
	{
		printf("%s", opname[node->exp->op]);
		dumpAST(node->exp->kids[0]);
		break;	
	}
	case KValue:
	{
		int tmp = node->val;
		if(node->val - (int)(node->val))
			printf("%d", (int)(node->val));
		else
			printf("%g", node->val);
		break;	
	}
	case KParenExp:
	{
		printf("(");
		dumpAST(node->exp->kids[0]);
		printf(")");
		break;	
	}
	case KBool:
	{
		if(node->val == 0)
			printf("false");
		else
			printf("true");
		break;	
	}
	case KConstString:
	{
		printf("\"%s\"", node->str);
		break;	
	}
	case KArrayAccess:
	{
		dumpAST(node->arrayaccess->id);
		dumpAST(node->arrayaccess->dim);
		break;	
	}
	case KCallStmt:
	{
		dumpAST(node->cstmt->ident);
		printf("(");
		dumpAST(node->cstmt->params);
		printf(")");
		break;	
	}
	case KWrite:
	{
		printf("write(");
		dumpAST(node->cstmt->params);
		printf(")");
		break;	
	}
	case KRead:
	{
		printf("read(");
		dumpAST(node->cstmt->params);
		printf(")");
		break;	
	}
	case KPrimary:
	{
		dumpAST(node->exp->kids[0]);
		break;	
	}
	default:
		printf("Unhandled ASTNode kind!\n");
	}
}


