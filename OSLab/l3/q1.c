#include "proc.h"

void callbackFunc(params argv){
    int status;
    wait(&status);
    printf("Child of q1 ended with status: %d\n", WEXITSTATUS(status));
}

int main()
{
    
}