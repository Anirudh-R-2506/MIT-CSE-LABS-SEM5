#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 3)
		exit(0);
	FILE *f1 = fopen(argv[1], "r");
	if (! f1){
		printf("File does not exist\n");
		exit(0);
	}
	FILE *f2 = fopen(argv[2], "w");
	if(! f2){
		printf("Dest file could not be opened");
		exit(0);
	}
	fseek(f1, 0, SEEK_END);
	long int size = ftell(f1);
	fseek(f1, 0, SEEK_SET);
	char c;
	long int pos = size - 1;
	while (pos >= 0){
		fseek(f1, pos, SEEK_SET);
		c = getc(f1);
		putc(c, f2);
		pos--;
	}
	printf("Copied to file %s\nFile size: %ld Bytes\n", argv[2], size);
}