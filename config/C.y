%{
#include <stdio.h>
#include <math.h>
#include <common.h>
Table symtab;
ASTTree ast;
ErrFactory errfactory;
extern int lparen_num;
bool thereareparam;	//to see if we should create a new symbol table in bloc (created in param when function with parameter)
bool is_funccc;

%}

%union {
   	float num;
	int ival;
   	char * ident; 
	char * str; 
	ASTNode node;
}

%token <ident>IDENTIFIER 
%token <num>CONSTANT CONSTANTF
%token <str>STRING_LITERAL 
%token LTEQ GTEQ EQEQ NOTEQ LT GT
%token ANDAND OROR NOT
%token PLUS MINUS MULT DIV MOD
%token EQ
%type  <ival> PLUS MINUS MULT DIV NOT ANDAND OROR EQ EQEQ LTEQ NOTEQ LT GTEQ GT MOD

%token TRUETOKEN
%token FALSETOKEN
%token <ident>TYPE_NAME

%token TYPEDEF 
%token INT FLOAT  CONST VOID
%token BOOL 

%token  IF ELSE  WHILE CONTINUE BREAK RETURN

%type  <node> primary_expression postfix_expression ArrayDimAccess argument_expression_list unary_expression  cast_expression multiplicative_expression 
%type  <node> additive_expression relational_expression equality_expression  
%type  <node> logical_and_expression  logical_or_expression conditional_expression assignment_expression 
%type  <node> expression declaration declaration_specifiers init_declarator_list init_declarator
%type  <node> type_specifier declarator direct_declarator ArrayDim parameter_type_list  parameter_list
%type  <node> parameter_declaration initializer initializer_list statement
%type  <node> compound_statement block_item_list block_item expression_statement selection_statement iteration_statement jump_statement 
%type  <node> translation_unit external_declaration function_definition 

%type  <ival> unary_operator

%start translation_unit
%%

primary_expression
	: IDENTIFIER
      	  {
	    	$$ = newgetVarName(symtab, $1); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| CONSTANT
	   {
	    	$$ = newNumber($1);
	   	setLoc($$, (Loc)&(@$));
	   }
	|CONSTANTF
	   {
	    	$$ = newNumber($1);
		$$->NodeType = newType("float");
	   	setLoc($$, (Loc)&(@$));
	   }
	| TRUETOKEN 
	  {
	    	$$ = newBool(1);
	   	setLoc($$, (Loc)&(@$));
	  }
	| FALSETOKEN 
	  {
	    	$$ = newBool(0);
	   	setLoc($$, (Loc)&(@$));
	  }
	| STRING_LITERAL
	  {
	    	$$ = newConstString($1); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| '(' expression ')'
	  {
	    	$$ = newParenExp($2);
	    	setLoc($$, (Loc)&(@$));
	  }
	;

postfix_expression
	: primary_expression
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| IDENTIFIER ArrayDimAccess
	  {
		$$ = newArrayAccess(newgetVarName(symtab, $1),$2);
		setLoc($$, (Loc)&(@$));
	  }
	| IDENTIFIER '(' ')'
	  {	
		if(!strcmp($1,"write"))
			$$=newWrite(NULL);
		else if(!strcmp($1,"read"))
			$$=newRead(NULL);
		else	
			$$ = newCall(newgetFuncName(symtab, $1),newArgList()); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| IDENTIFIER '(' argument_expression_list ')'
	  {
		if(!strcmp($1,"write"))
			$$=newWrite($3);
		else if(!strcmp($1,"read"))
			$$=newRead($3);
		else
			$$ = newCall(newgetFuncName(symtab, $1),$3); 
		setLoc($$, (Loc)&(@$));
	  }
	;

ArrayDimAccess	: 
	'[' expression ']'
	{
		$$ = newArrayDim();
		addLast($$->list, $2);
		setLoc($$, (Loc)&(@$));
	}
	| ArrayDimAccess '[' expression ']'
	{
		addLast($1->list, $3);
		$$=$1;
	}
	;

argument_expression_list
	: assignment_expression
	  {
		$$=newArgList();
		addLast($$->list, $1);
	  }
	| argument_expression_list ',' assignment_expression
	   {
		addLast($1->list, $3);
		$$=$1;
	   }
	;

unary_expression
	: postfix_expression
	  {
		$$=newPrimary($1);
		setLoc($$, (Loc)&(@$));
	  }
	| unary_operator cast_expression
	  {
	    	$$ = newUnaryExp($1, $2); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

unary_operator
	: PLUS {$$ = $1;}
	| MINUS{$$ = $1;}
	| NOT  {$$ = $1;}
	;

cast_expression
	: unary_expression
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;

multiplicative_expression
	: cast_expression
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| multiplicative_expression MULT cast_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| multiplicative_expression DIV cast_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| multiplicative_expression MOD cast_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

additive_expression
	: multiplicative_expression
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| additive_expression PLUS multiplicative_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| additive_expression MINUS multiplicative_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

relational_expression
	: additive_expression
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| relational_expression LT additive_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| relational_expression GT additive_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| relational_expression LTEQ additive_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| relational_expression GTEQ additive_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

equality_expression
	: relational_expression
    	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| equality_expression EQEQ relational_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| equality_expression NOTEQ relational_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

logical_and_expression
	: equality_expression
    	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| logical_and_expression ANDAND equality_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

logical_or_expression
	: logical_and_expression
    	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| logical_or_expression OROR logical_and_expression
	  {
	    	$$ = newInfixExp($2, $1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

conditional_expression
	: logical_or_expression
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;

assignment_expression
	: conditional_expression
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| unary_expression EQ assignment_expression
	  {
	    	$$ = newAssignment($2, $1, $3);
	    	setLoc($$, (Loc)&(@$));
	  }
	;

expression
	: assignment_expression
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| expression ',' assignment_expression
	  {
	    	$$ = newCommaExp($1, $3); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

declaration
	: declaration_specifiers init_declarator_list ';'
	  {
		if(thereareparam==1)
		{
			yyerror("\nerror : function declaration doesn't have parameters\n");
			return 0;
		}		
		if(!strcmp($1->type,"void") && !is_funccc)
		{
			yyerror("\nerror : variable cannot be void\n");
			return 0;
		}
		switch($1->type0_const1_typedef2)
		{	
			case 0:{
				setListType($2->list,$1);
				$$ = newDeclaration(symtab,$1,$2);
				break;
			}
			case 1:{
				setListType($2->list,$1);
				$$ = newConstDeclaration(symtab,$1,$2);
				break;
			}
			case 2:{
				setRenameListType($2->list,$1);
				$$ = newTypedefDeclaration($1,$2);
				break;
			}
			default: yyerror("\nerror : type problem\n");return 0;break;
		}
		setLoc($$, (Loc)&(@$));
	  }
	;

declaration_specifiers
	: TYPEDEF type_specifier
	  {
		$2->type0_const1_typedef2 = 2;
		$$=$2;
		setLoc($$, (Loc)&(@$));
	  }
	| type_specifier
	  {
		$1->type0_const1_typedef2 = 0;
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| CONST type_specifier
	  {
		$2->type0_const1_typedef2 = 1;
		$$=$2;
		setLoc($$, (Loc)&(@$));
	  }
	;

init_declarator_list
	: init_declarator
	  {
		$$=newDeclList();
		addLast($$->list, $1);
		setLoc($$, (Loc)&(@$));
	  }
	| init_declarator_list ',' init_declarator
	  {
		addLast($1->list, $3);
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;

init_declarator
	: declarator
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| declarator EQ initializer
	  {
		SetInitialValue(symtab,$1,$3);
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;

type_specifier
	: VOID 		{$$ = newType("void");}
	| INT 		{$$ = newType("int");}
	| FLOAT 	{$$ = newType("float");}
	| BOOL 		{$$ = newType("bool");}
	//| IDENTIFIER 	{if(!type_exist_sym(symtab,$1)) yyerror("error: type %s dosn't exist!",$1);
	//		 $$ = newType($1);}
	;

declarator
	: direct_declarator
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;


direct_declarator
	: IDENTIFIER
	  {
		is_funccc=FALSE;
		$$ = newVarName(symtab,$1);
		SetArrayDim(symtab,$$,newArrayDim());
		setLoc($$, (Loc)&(@$));
	  }
	| IDENTIFIER ArrayDim
	  {
		is_funccc=FALSE;
		$$ = newVarName(symtab,$1);
		SetArrayDim(symtab,$$,$2);
		setLoc($$, (Loc)&(@$));
	  }
	| IDENTIFIER '('  {	symtab=newTable(symtab);				////// newtable
				thereareparam=1;	}
	  parameter_type_list ')'
	  {
		is_funccc=TRUE;
		$$ = newFuncDecl(symtab->parent,$1,$4);
		setLoc($$, (Loc)&(@$));
	  }
	| IDENTIFIER '(' ')'
	  {
		is_funccc=TRUE;
		$$ = newFuncDecl(symtab,$1,NULL);
		setLoc($$, (Loc)&(@$));
	  }
	;

ArrayDim	
	: '[' assignment_expression ']'
	  { 
		$$=newArrayDim();
		addLast($$->list, newNumber(EvalExp($2)));
		setLoc($$, (Loc)&(@$));
	  }
	| ArrayDim '[' assignment_expression ']'
	  {
		addLast($1->list, newNumber(EvalExp($3)));
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;
parameter_type_list
	: parameter_list
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;

parameter_list
	: parameter_declaration
	  {
		$$=newParamList();
		addLast($$->list, $1);
		setLoc($$, (Loc)&(@$));
	  }
	| parameter_list ',' parameter_declaration
	  {
		addLast($1->list, $3);
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;

parameter_declaration
	: declaration_specifiers declarator
	  {	
		if(!strcmp($1->type,"void"))
		{
			yyerror("\nerror : variable cannot be void\n");
			return 0;
		}
		if(is_funccc)		
		{
			yyerror("\nerror : parameter cannot be function\n");
			return 0;
		}
		switch($1->type0_const1_typedef2)
		{	
			case 0:{
				if($2->kind!=KVarName || $2->sym->dim > 0){
					yyerror("\nerror: not allowed kind of parameter!\n");return 0;}
				if($1->NodeType)
					if(type_exist_sym(symtab,$1->type)->dim > 0){
						yyerror("\nerror: not allowed parameter type(cannot be array)!\n");return 0;}
			//in the var
				$2->NodeType = $1;
				$2->sym->type = 1;		//becomes var
				$2->sym->addr = symtab->dx;
				symtab->dx = symtab->dx + 1;
				$2->sym->lev = symtab->lev;
			//
				$2->sym->symType = $1;
				$$=newParam($1, $2); 
				break;
			}
			case 1:{
				yyerror("\nerror: not allowed parameter type(cannot be const)!\n");return 0;
				break;
			}
			case 2:{
				yyerror("\nerror: not allowed parameter type(cannot be typedef)!\n");return 0;
				break;
			}
			default: yyerror("\nerror : type problem\n");return 0;break;
		}
		setLoc($$, (Loc)&(@$));
	  }
	;

initializer
	: assignment_expression
	  {
		$$=$1;	
		setLoc($$, (Loc)&(@$));
	  }
	| '{' initializer_list '}'
	  {
		$$=$2;	
		setLoc($$, (Loc)&(@$));
	  }
	| '{' initializer_list ',' '}'
	  {
		$$=$2;	
		setLoc($$, (Loc)&(@$));
	  }
	;

initializer_list
	: initializer
	 {
		$$=newListInitExp();	
		addLast($$->list, $1);
		setLoc($$, (Loc)&(@$));
	 }
	| initializer_list ',' initializer
	  {	
		addLast($1->list, $3);
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;

statement
	: compound_statement
	  {
		$$ = newStmt($1); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| expression_statement
	  {
		$$ = newStmt($1); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| selection_statement
	  {
		$$ = newStmt($1); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| iteration_statement
	  {
		$$ = newStmt($1); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| jump_statement
	  {
		$$ = newStmt($1); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

compound_statement
	: '{' '}'
	  {
		$$=newBlock();
		$$->dx = symtab->dx;			//dx
		if(thereareparam)
		{
			thereareparam=0;
			if(symtab->parent->parent != NULL)
				symtab->parent->dx = symtab->dx;
			symtab=symtab->parent;			/////////////// parent table
		}
		setLoc($$, (Loc)&(@$));
	  }	
	| '{'   {	 
			 if(thereareparam==0)
				symtab=newTable(symtab);			////// newtable
			 else
				thereareparam=0;
		} 
	  block_item_list '}'
	  {
		$$=$3;
		$$->dx = symtab->dx;			//dx
		if(symtab->parent->parent != NULL)
				symtab->parent->dx = symtab->dx;
		symtab=symtab->parent;			/////////////// parent table
		setLoc($$, (Loc)&(@$));
	  }
	;

block_item_list
	: block_item
	  {
		$$=newBlock();
		addLast($$->list, $1);
		setLoc($$, (Loc)&(@$));
	  }
	| block_item_list block_item
	  {
		addLast($1->list, $2);
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;

block_item
	: declaration
	  {
	    	$$ = $1; 
	    	setLoc($$, (Loc)&(@$));
	  }
	| statement
	  {
	    	$$ = $1; 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

expression_statement
	: ';'
	  {
	    	$$ = newExpStmt(NULL); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| expression ';'
	  {
		$$ = newExpStmt($1); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

selection_statement
	: IF '(' expression ')' statement
	  {
	    	$$ = newIfStmt($3, $5); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| IF '(' expression ')' statement ELSE statement
	  {
	    	$$ = newIfElseStmt($3, $5, $7); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

iteration_statement
	: WHILE '(' expression ')' statement
	  {
	    	$$ = newWhileStmt($3, $5); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

jump_statement
	: CONTINUE ';'
	  {
	    	$$ = newContinue(); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| BREAK ';'
	  {
	    	$$ = newBreak(); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| RETURN ';'
	  {
	    	$$ = newReturn(NULL); 
	    	setLoc($$, (Loc)&(@$));
	  }
	| RETURN expression ';'
	  {
	    	$$ = newReturn($2); 
	    	setLoc($$, (Loc)&(@$));
	  }
	;

translation_unit
	: external_declaration
	  {
	    	$$ = newProgram();
		addLast($$->list, $1);
		$$->dx = symtab->dx;			//dx
		$$->num_funcs = symtab->func_num;
		ast->root = $$;
	  }
	| translation_unit external_declaration
	  {
	    	addLast($1->list, $2);
	   	$$ = $1;
		$$->dx = symtab->dx;			//dx
		$$->num_funcs = symtab->func_num;
	   	setLoc($$, (Loc)&(@$));
	  }
	;

external_declaration
	: function_definition
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	| declaration
	  {
		$$=$1;
		setLoc($$, (Loc)&(@$));
	  }
	;

function_definition
	: declaration_specifiers declarator compound_statement
	  {
		$$ = newFuncDef($1,$2,$3);
	   	setLoc($$, (Loc)&(@$));
	  }
	| declarator compound_statement
	  {
		$$ = newFuncDef(newType("int"),$1,$2);
	   	setLoc($$, (Loc)&(@$));
	  }
	;


%%

extern char yytext[];
extern int column;

int yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main(int argc, char *argv[])
{
	thereareparam = 0;	
	symtab = newTable(NULL);//newFuncName(symtab, "write");newFuncName(symtab, "read");
	errfactory = newErrFactory();
	ast = newAST();
	printf("Parsing ...\n");
  	yyparse();
	printf("\n\nDump the program from the generated AST:\n");
	printf("\n==========================================\n");
	dumpAST(ast->root);
	binarycode(ast->root);
	//destroyAST(&ast->root);
	dumpErrors(errfactory);
	dumpWarnings(errfactory);
	if(symtab)
		destroyTable(&symtab);
	destroyErrFactory(&errfactory);
 	return(0);
}


