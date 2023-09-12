#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc < 2)
        exit(-1);
    if(symlink(argv[1], argv[2]) == 0){
        printf("Link created at: %s\n", argv[2]);
        printf("Unlinking...\n");
        if(unlink(argv[2]) == 0){
            printf("Unlinked\n");
        }
        else{
            printf("Could not unlink");
        }
    }
}