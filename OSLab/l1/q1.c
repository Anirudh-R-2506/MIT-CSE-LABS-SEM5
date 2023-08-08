#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char fname[100] = "notes.txt";
	char sub[100];
	printf("Enter substring: ");
	scanf("%[^\n]s", sub);
	int buff = open(fname, O_RDONLY);
	if (buff == -1){
		printf("File not found\n");
		return 0; 
	}
	char ch, *p;
	char line[250] = "";
	while(read(buff, &ch, 1) > 0){
		if(strcmp(line, "") == 0)
			strcpy(line, &ch);
		else
			strcat(line, &ch);
		if(strcmp(&ch, "\n") == 3){
			if(strstr(line, sub))
				printf("%s\n", line);
			strcpy(line, "");
		}
	}
}