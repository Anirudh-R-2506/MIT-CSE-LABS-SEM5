#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    struct stat fs;
    if (argc < 2 || stat(argv[1], &fs)){
        exit(-1);
    }
    printf("Inode: %ld\n", fs.st_ino);
    return 0;
}