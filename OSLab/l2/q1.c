#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char dir[256];
    getcwd(dir, sizeof(dir));
    printf("%s\n", dir);
    DIR *d;
    struct dirent *e;
    struct stat statbuff;
    if ((d = opendir(dir)) == NULL){
        printf("Could not open directory");
        exit(0);
    }
    chdir(dir);
    printf("File\tPermissions\n");
    while((e = readdir(d)) != NULL){
        lstat(e->d_name, &statbuff);
        printf("%s\t", e->d_name);
        printf( (S_ISDIR(statbuff.st_mode)) ? "d" : "-");
        printf( (statbuff.st_mode & S_IRUSR) ? "r" : "-");
        printf( (statbuff.st_mode & S_IWUSR) ? "w" : "-");
        printf( (statbuff.st_mode & S_IXUSR) ? "x" : "-");
        printf( (statbuff.st_mode & S_IRGRP) ? "r" : "-");
        printf( (statbuff.st_mode & S_IWGRP) ? "w" : "-");
        printf( (statbuff.st_mode & S_IXGRP) ? "x" : "-");
        printf( (statbuff.st_mode & S_IROTH) ? "r" : "-");
        printf( (statbuff.st_mode & S_IWOTH) ? "w" : "-");
        printf( (statbuff.st_mode & S_IXOTH) ? "x" : "-");
        printf("\n");
    }
    closedir(d);
}