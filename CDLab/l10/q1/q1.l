%{
#include "q1.tab.h"
//filename.tab.h : here both flex and bison
%}
%%
"let" {return LET;}
"int" {return INT;}
"char" {return CHAR;}
"bool" {return BOOL;}
"float" {return FLOAT;}
";" {return SC;}
"," {return CO;}
\n {return NL ;}
[a-zA-Z][a-zA-Z0-9_]* {return ID; }
%%
int yywrap()
{return 1;
}
void main ()
{
	printf("Enter the expression\n");
	yyparse();
}