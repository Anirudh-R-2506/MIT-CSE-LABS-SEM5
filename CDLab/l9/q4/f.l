%{
	
%}
%%
[A-Z] {

}
%%
int yywrap() { return 1;}
int main()
{
printf("Enter str: ");
yylex();
printf("pos: %d\nneg: %d\nposf: %d\nnegf: %d\n", p, n, pf, nf);
}