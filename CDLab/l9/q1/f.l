%{
	int v = 0;
	int c = 0;
%}
%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
%%
int yywrap() { return 1;}
int main()
{
printf("Enter str: ");
yylex();
printf("Vowels: %d\nConsonants: %d\n", v, c);
}