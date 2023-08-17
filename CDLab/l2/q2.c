#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

#define MAX_LINE 1000
#define P1 "[A-Za-z]+\\smain\\("
#define P2 "[A-Za-z]+\\smain\\s\\("

regex_t reg;
regex_t reg2;

int isMain(char *s)
{
	return regexec(&reg, s, 0, NULL, 0) && regexec(&reg2, s, 0, NULL, 0);
}


int main(int argc, char *argv[])
{
	regcomp(&reg, P1, REG_EXTENDED);
	regcomp(&reg2, P2, REG_EXTENDED);
	if (argc != 2)
		exit(0);
	FILE *a, *b;
	if ((a = fopen(argv[1], "r")) == NULL)
		exit(0);
	b = fopen("q2out.txt", "w");
	char l[MAX_LINE];
	int f = 0;
	while(fgets(l, MAX_LINE, a)){
		if (! f && ! isMain(l))
			f = 1;
		if (l[0] == '#' && ! f)
			continue;
		fputs(l, b);
	}
	printf("Directives removed!\n");
}