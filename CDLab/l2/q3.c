#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE 1000

char* strtoupper(char* str)
{
	int len = strlen(str);
	int i;
	char* s = (char*)malloc(sizeof(char) * len);
	for(i=0; i<len; i++){
		s[i] = toupper(str[i]);
	}
	return (s);
}

char *getWord(FILE *fp){
    char word[100];
    int ch, i=0;

    while(EOF!=(ch=fgetc(fp)) && !isalpha(ch))
        ;//skip
    if(ch == EOF)
        return NULL;
    do{
        word[i++] = tolower(ch);
    }while(EOF!=(ch=fgetc(fp)) && isalpha(ch));

    word[i]='\0';
    return strdup(word);
}

int isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return 1;
    return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2){
		printf("Pass a file name\n");
		exit(0);
	}
	FILE *fa, *fb;
	int ca;
	char *ws = " ";
	fa = fopen(argv[1], "r");
	if (fa == NULL){
		printf("%s file could not be opened", argv[1]);
		exit(0);
	}
	fb = fopen("q3out.txt", "w");
	char *l;
	while(l = getWord(fa)){
		if (isKeyword(l)){
			l = strtoupper(l);
		}
		fputs(l, fb);
	}
	printf("File modified to q3out.txt");
}