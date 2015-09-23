/*
 * Common definitions and declarations for compilers
 * Author: Thierry (thierry@ustc.edu.cn)
 */
#ifndef _COMMON_H_
#define _COMMON_H_
#include "util.h"

// operator kinds
// You could add more kinds of error messages into errcfg.h
enum {
#define opxx(a, b) OP_##a,
#include "op.h"
	OPLAST
};

//extern char **opname;

// symbolic table
struct table;
typedef struct symbol {
	char	*name;	// name of the symbol
	bool	isInitial;	// whether it is initialized
	short	type;	// type of the symbol
                    //type : 0=const,1=int,2=typedef,3=procedure
	long    addr;
	long 	lev;
	bool Init_is_const;
	struct astnode	* symType;
	//bool	isType;		//whether used typedef (false for variable and func name)
	union{
   	struct table * tab;
	struct astnode  **val;	// value of the symbol
	struct astnode  *paramlists;
	};
	int function_link_pos;
	int dim;
	int *dimsizes;
} *Symbol;

typedef struct entry {
	struct symbol sym;
	struct entry *next;
} *Entry;

typedef struct table {
	// a hashtable to store symbols
	long dx;
	long lev;
	long func_num;
	struct table * parent;
	struct entry *buckets[256];
} *Table;
#define HASHSIZE 256

// Function declarations corresponding to symbolic table
Table 	newTable(Table T);
Symbol 	lookup(Table ptab, const char *name, short kind);
Symbol 	getSym(Table ptab, const char *name, short kind);
float 	getVal(Table ptab, const char *name);
Symbol 	setVal(Table ptab, const char *name, float val);//,short type);
void 	destroyTable();
/****  P4  ****/
Symbol  setProc(Table ptab, const char *name);
/**************/

// Error/warning message
// You could add more kinds of error messages into errcfg.h
enum {
#define errxx(a, b) a,
#include "errcfg.h"
	LASTERR
};

// An error/warning message
typedef struct errmsg {
	bool	isWarn;
	int 	type;
	char 	*msg;
	int	line;
	int	column;
} *Errmsg;

// Error factory
typedef struct errfactory {
	List	errors;
	List	warnings;
} *ErrFactory;

// Function declarations on error message management
Errmsg	newError	(ErrFactory errfactory, int type, int line, int col);
Errmsg	newWarning	(ErrFactory errfactory, int type, int line, int col);
void	dumpErrmsg	(Errmsg error);
ErrFactory newErrFactory();
void	dumpErrors	(ErrFactory errfactory);
void	dumpWarnings	(ErrFactory errfactory);
void	destroyErrFactory(ErrFactory *errfact);

// abstract syntax tree
// Structure for tracking locations, same as YYLTYPE in y.tab.h
typedef struct location {
	int first_line;
	int first_column;
	int last_line;
	int last_column;
} *Loc;

typedef struct {
	struct astnode  *type;
	struct astnode  *ident;
	struct astnode  *paramlist;
	struct astnode  *block;
} *Func;

typedef struct {
	struct astnode  *type;
	struct astnode  *idlist;
} *Declaration;
/*
typedef struct {
	struct astnode  *decl;
	struct astnode  *stmts;
} *Block;
*/
typedef struct {
	struct astnode *stat;
} *Stmt;

typedef struct {
	struct astnode	*Ccond;
	struct astnode	*Cstmt;
	struct astnode	*Estmt;
} *IfStmt;

typedef struct {
	struct astnode	*Ccond;
	struct astnode	*Cstmt;
} *WhileStmt;

typedef struct {
	int 	op;
	bool isconst;
	float 	val;
	struct astnode	*kids[2];// kids of the AST node
} *Exp;

typedef struct {
	struct astnode *exp;
} *ExpStmt;

typedef struct {
	struct astnode	*id;
	struct astnode	*dim;
} *ArrayAccess;

typedef struct {
	struct astnode *ident;
	struct astnode *params;
} *CallStmt;



typedef struct astnode{
	enum {
		KProgram = 0x200,
		KMultiDecl,
		KMultiFuncDef,
		KFuncDef,
		KFuncName,
		KType,
		KParamList,
		KConstDecl,
		KDecl,
		KTypedefDecl,
		KDeclList,
		KVarDeclList,
		KParam,
		KVarName,
		KFuncDecl,
		KArrayDim,
		KListInitExp,
		KBlock,
		KMultiStmt,
		KStmt,
		KExpStmt,
		KBreak,
		KContinue,
		KReturn,
		KIfStmt,
		KIfElseStmt,
		KWhileStmt,
		KInfixExp,
		KCommaExp,
		KAssignExp,
		KUnaryExp,
		KValue,
		KParenExp,
		KBool,
		KConstString,
		KArrayAccess,
		KCallStmt,
		KArgList,
		KPrimary,
		KRead,
		KWrite
		
	} kind;	// kind of the AST node
	union {
		List list;
		Func func;
		char * type;
		Declaration declaration;
		//Block  block;
		Stmt  stmt;	
		ExpStmt  estmt;	
		IfStmt istmt;
		WhileStmt wstmt;
		Exp   exp;
		float  val;
		char * str;
		Symbol sym;
		ArrayAccess arrayaccess;
		CallStmt cstmt;
		struct astnode  * retexp;
	};
	struct astnode * NodeType;
	union {
		long dx;
		long type0_const1_typedef2;		//0 if type, 1 if const type, 2 if typedef type
	};
	long num_funcs;
	Loc 	loc;	// locations
} *ASTNode;

typedef struct ASTtree {
	ASTNode root;
} *ASTTree;

// functions for creating various kinds of ASTnodes
ASTTree newAST();
void destroyAST(ASTNode *pnode);
Loc	setLoc(ASTNode node, Loc loc);

ASTNode newProgram();
ASTNode newMultiDeclaration();
ASTNode newMultiFuncDef();
ASTNode newFuncDef(ASTNode type, ASTNode decl, ASTNode bloc);
ASTNode newFuncName(Table ptab, char *name);
ASTNode newType(char *name);
ASTNode newParamList();
ASTNode newConstDeclaration(Table ptab, ASTNode type, ASTNode idlist);
ASTNode newDeclaration(Table ptab, ASTNode type, ASTNode idlist);
ASTNode newTypedefDeclaration(ASTNode type, ASTNode idlist);
ASTNode newDeclList();
ASTNode newVarDeclList();
ASTNode newParam(ASTNode type, ASTNode vname);			// uses declaration
ASTNode newVarName(Table ptab, char *name);
ASTNode newFuncDecl(Table ptab, char *name, ASTNode paramlists);
ASTNode newArrayDim();
ASTNode newListInitExp();
ASTNode newBlock();
ASTNode newMultiStmt();
ASTNode newStmt(ASTNode nod);
ASTNode newExpStmt(ASTNode nod);
void destroyExpStmt(ExpStmt *pnode);
ASTNode newBreak();
ASTNode newContinue();
ASTNode newReturn(ASTNode exp);		//NULL for return;
ASTNode newIfStmt(ASTNode cond, ASTNode stmts);
ASTNode newIfElseStmt(ASTNode cond, ASTNode stmts1, ASTNode stmts2);
ASTNode newWhileStmt(ASTNode cond, ASTNode stmts);
ASTNode newInfixExp(int op, ASTNode left, ASTNode right);
ASTNode newCommaExp(ASTNode left, ASTNode right);
ASTNode newAssignment(int op, ASTNode left, ASTNode right);
ASTNode newUnaryExp(int op, ASTNode exp);
ASTNode newgetVarName(Table ptab, char *name);
ASTNode newgetFuncName(Table ptab, char *name);
ASTNode newNumber(float value);
ASTNode newParenExp(ASTNode exp);
ASTNode newBool(int val);		//0 : false;  1 : true
ASTNode newConstString(char *str);
ASTNode newArrayAccess(ASTNode id_nod, ASTNode pos_dim);
ASTNode newCall(ASTNode name, ASTNode params); 
ASTNode newWrite(ASTNode params);
ASTNode newRead(ASTNode params);
ASTNode newArgList();
ASTNode newPrimary(ASTNode prim);

void    setListType(List list,ASTNode type);
void    setRenameListType(List list,ASTNode type);
void    SetInitialValue(Table ptab,ASTNode var, ASTNode values);
void    SetArrayDim(Table ptab,ASTNode var, ASTNode arraydim);
float   EvalExp(ASTNode const_expr);
Symbol 	type_exist_sym(Table ptab, char *name);

void    dumpAST(ASTNode node);

void binarycode(ASTNode root);

#endif // !def(_COMMON_H_)
