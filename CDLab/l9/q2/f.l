%{
	int l = 0, b = 0, w = 0, c = 0;
%}
%%
[\n] {l++; c+=yyleng;}
[  \t] {b++; c+=yyleng;}
[^\t\n ]+ {w++; c+=yyleng;}
%%
int yywrap() { return 1;}
int main()
{
printf("Enter str: ");
yylex();
printf("Lines: %d\nBlanks: %d\nWords: %d\nChars: %d\n", l, b, w, c);
}