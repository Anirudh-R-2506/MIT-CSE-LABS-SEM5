#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1000


int main(int argc, char *argv[]){
	if(argc != 3)
		exit(0);
	FILE *f1 = fopen(argv[1], "r");
	if (! f1){
		printf("File f1 does not exist\n");
		exit(0);
	}
	FILE *f2 = fopen(argv[2], "r");
	if(! f2){
		printf("File f2 could not be opened");
		exit(0);
	}
	FILE *f3 = fopen("res.txt", "w");
	if(! f3){
		printf("File f3 could not be opened");
		exit(0);
	}
	int lines = 0;
	char l1[MAX_LINE], l2[MAX_LINE];
	while(fgets(l1, MAX_LINE, f1) && fgets(l2, MAX_LINE, f2)){
		if (lines % 2 == 0){
			fputs(l1, f3);
		}
		else{
			fputs(l2, f3);
		}
		lines++;
	}
	printf("Lines copied to res.txt\n");
	return 0;
}