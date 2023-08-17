#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	fb = fopen("q1out.txt", "w");
	ca = getc(fa);
	int enc = 0;
	while (ca != EOF){
		if (ca == ' ' || ca == '\t'){
			if (! enc){
				fputs(ws, fb);
				enc = 1;
			}
		}
		else{
			putc(ca, fb);
			enc = 0;
		}
		ca = getc(fa);
	}
	printf("File modified to q1out.txt");
}