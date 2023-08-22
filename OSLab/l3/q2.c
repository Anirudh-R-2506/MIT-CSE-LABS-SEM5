#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int status;
    pid_t pid;
    pid = fork();
    if (pid == -1){
        perror("Child not created");
        exit(0);
    }
    else if (pid == 0){
        printf("Executing in child\n");
        if(execlp("./q1.o", "./q1.o", NULL) == -1){
            perror("Error while executing");
            exit(-1);
        }
        exit(0);
    }
    wait(&status);
    printf("Child ended with status: %d\n", WEXITSTATUS(status));
}