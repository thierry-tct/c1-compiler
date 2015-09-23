#include <stdio.h>

#define cxmax      20000           // size of code array
#define MAX_STRING_NUM 5000

enum object {
    constant, variable, proc
};

enum fct {
    lit=0, opr, lod, sto, cal, Int, jmp, jpc, lar, sar, jpe ,init         // functions
};

enum opc {
    ret=0, neg, add, minuss, mult, divv, mod, andand, oror, eq, neq, lt, lte, gt, gte, readd,
writee,writes, notnot         // operators
};

enum type {
    _INT=0,_FLOAT, _BOOL,_OPC
};

typedef struct{
    enum fct f;		// function code
    int l; 		// level
    union
	{
		double d;
		int i;
		bool b;
		enum opc op;
	}v;		// value
	enum type t;	//type
} instruction;

static long cx=0, breakcx, continuecx,string_num=0, Main_addr=-1, listcode_cx=0;               // code allocation index

bool in_while=FALSE,lod_now=TRUE,read_now=FALSE,is_String=FALSE;

static instruction code[cxmax+1];

char mnemonic[12][4+1];

char * lesstrings[MAX_STRING_NUM];

static Symbol floating_sym;

static long lev=0;		// current depth of block nesting


