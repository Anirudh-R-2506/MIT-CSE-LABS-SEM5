#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char cwd[256];

void printFiles(char *dir)
{
    DIR *d;
    struct dirent *e;
    struct stat statbuff;
    if ((d = opendir(dir)) == NULL){
        printf("Could not open directory");
        exit(0);
    }
    chdir(dir);
    while((e = readdir(d)) != NULL){
        lstat(e->d_name, &statbuff);
        if (! S_ISDIR(statbuff.st_mode)){
            if(strcmp(dir, cwd) == 0)
                printf("%s\n", e->d_name);
            else
                printf("%s/%s\n", dir, e->d_name);
        }
        else{
            if(strcmp(e->d_name, ".") != 0 && strcmp(e->d_name, "..") != 0){
                printFiles(e->d_name);
            }
        }
    }
}

int main()
{
    getcwd(cwd, sizeof(cwd));
    printFiles(cwd);
}