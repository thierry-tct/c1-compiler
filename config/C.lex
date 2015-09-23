/*C.lex*/
%{
#include "common.h"
#include <stdio.h>
#include "C.tab.h"

void count(void);
%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]




%%
"/*"			{ comment(); }
"//"[^\n]*              { /* consume //-comment */ }

"true"			{ count(); return(TRUETOKEN);}	
"false"			{ count(); return(FALSETOKEN);}	
"bool"			{ count(); return(BOOL); }
"break"			{ count(); return(BREAK); }
"const"			{ count(); return(CONST); }
"continue"		{ count(); return(CONTINUE); }
"else"			{ count(); return(ELSE); }
"float"			{ count(); return(FLOAT); }
"if"			{ count(); return(IF); }
"int"			{ count(); return(INT); }
"return"		{ count(); return(RETURN); }
"typedef"		{ count(); return(TYPEDEF); }
"void"			{ count(); return(VOID); }
"while"			{ count(); return(WHILE); }

{L}({L}|{D})*		{ count(); return(check_type()); }

0[xX]{H}+    		{ count(); yylval.num = strtol (yytext,NULL,0); return(CONSTANT);}
0[0-7]*		 	{ count(); yylval.num = strtol (yytext,NULL,0); return(CONSTANT);}
[1-9]{D}*		{ count(); yylval.num = strtol (yytext,NULL,0); return(CONSTANT);}
[0-9]+\.[0-9]+ 		{ count(); sscanf(yytext,"%f",&yylval.num); return(CONSTANTF);}


L?\"(\\.|[^\\"\n])*\"	{ count(); yylval.str=(char *)malloc(sizeof(char)*(yyleng-1));
			memcpy (yylval.str,yytext+1,yyleng-2);
			yylval.str[yyleng-2]='\0';return(STRING_LITERAL); }

"&&"			{ count(); yylval.ival = OP_ANDAND; return(ANDAND); }
"||"			{ count(); yylval.ival = OP_OROR; return(OROR); }
"<="			{ count(); yylval.ival = OP_LTEQ; return(LTEQ); }
">="			{ count(); yylval.ival = OP_GTEQ; return(GTEQ); }
"=="			{ count(); yylval.ival = OP_EQEQ; return(EQEQ); }
"!="			{ count(); yylval.ival = OP_NOTEQ; return(NOTEQ); }
";"			{ count(); return(';'); }
"{"			{ count(); return('{'); }
"}"			{ count(); return('}'); }
","			{ count(); return(','); }
"="			{ count(); yylval.ival = OP_EQ; return(EQ); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
"["			{ count(); return('['); }
"]"			{ count(); return(']'); }
"!"			{ count(); yylval.ival = OP_NOT; return(NOT); }
"-"			{ count(); yylval.ival = OP_MINUS; return(MINUS); }
"+"			{ count(); yylval.ival = OP_PLUS; return(PLUS); }
"*"			{ count(); yylval.ival = OP_MULT; return(MULT); }
"/"			{ count(); yylval.ival = OP_DIV; return(DIV); }
"%"			{ count(); yylval.ival = OP_MOD; return(MOD); }
"<"			{ count(); yylval.ival = OP_LT; return(LT); }
">"			{ count(); yylval.ival = OP_GT; return(GT); }

[ \t\v\n\f]		{ count(); }
.			{ /* Add code to complain about unmatched characters */ }

%%

int yywrap(void)
{
	return 1;
}


int comment(void)
{
	char c, prev = 0;
  
	while ((c = input()) != 0)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	error("unterminated comment");
}


int column = 0;

void count(void)
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


int check_type(void)
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return TYPE_NAME;
*
*	return IDENTIFIER;
*/

/*
*	it actually will only return IDENTIFIER
*/
	yylval.ident=(char *)malloc(sizeof(char)*(yyleng+1));
	memcpy (yylval.ident,yytext,yyleng);
	yylval.ident[yyleng]='\0';
	return IDENTIFIER;
}
