%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yywrap();
int yyerror();
%}

%token NL NUMBER INT CHAR BOOL FLOAT ID LET SC CO
%define parse.error verbose

%%
start : declist NL
;
declist : declist decl SC | decl {printf("Valid\n");exit(0);}
decl : startdec type singledec
startdec : LET
type : INT 
	   | CHAR			  
	   | BOOL
	   | FLOAT 
	   | NL
singledec : singledec CO decinit 
			| decinit
decinit : ID
;
%%
int yyerror(char *msg)
{
printf("Invalid Expression: %s\n", msg);
exit(0);
}

