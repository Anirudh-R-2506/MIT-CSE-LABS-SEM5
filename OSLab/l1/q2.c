#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *fname = argv[1];
	int buff = open(fname, O_RDONLY);
	if(buff == -1){
		printf("File not found\n");
		return 0;
	}
	char line[250] = "";
	char ch;
	int c = 0;
	while(read(buff, &ch, 1) > 0){
		if(strcmp(line, "") == 0)
			strcpy(line, &ch);
		else
			strcat(line, &ch);
		if(ch == '\n'){			
			c++;
			if(c <= 2){			
				printf("%s\n", line);
				strcpy(line, "");
			}
			else{
				while(1){
					printf("n to print next line and q to quit: ");
					char next = getchar();
					if(next == 'q')
						exit(0);
					else if(next == 'n'){
						c = 0;
						break;
					}
				}
			}
		}
	}
}