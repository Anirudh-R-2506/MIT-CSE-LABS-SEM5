#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

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
        /* pid = getpid(); */
        exit(0);
    }
    wait(NULL);
    printf("In parent, PIDs of parent: %d, process: %d, child: %d\n", getppid(), getpid(), pid);
}