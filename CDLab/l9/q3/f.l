%{
	int p = 0, n = 0, pf = 0, nf = 0;
%}
%%
[-][0-9]+ {n++;}
[0-9]+ {p++;}
[-][0-9]+[.][0-9]+ {nf++;}
[0-9]+[.][0-9]+ {pf++;}
%%
int yywrap() { return 1;}
int main()
{
printf("Enter str: ");
yylex();
printf("pos: %d\nneg: %d\nposf: %d\nnegf: %d\n", p, n, pf, nf);
}