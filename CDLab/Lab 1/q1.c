#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 2)
		exit(0);
	FILE *f1 = fopen(argv[1], "r");
	if (! f1){
		printf("File does not exist\n");
		exit(0);
	}
	int lines = 0;
	int chars = 0;
	char c = getc(f1);
	while (c != EOF){
		(c == '\n') ? lines++ : chars++;
		c = getc(f1);
	}
	printf("Lines: %d\nChars: %d\n", lines, chars);
}