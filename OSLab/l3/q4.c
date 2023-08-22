#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == -1){
        perror("Child not created");
        exit(0);
    }
    else if (pid == 0){
        printf("In child, PIDs of parent: %d, process: %d\n", getppid(), getpid());
        if (execlp("ps", "ps", NULL) == -1){
            perror("Could not execlp");
        }
        exit(0);
    }
}