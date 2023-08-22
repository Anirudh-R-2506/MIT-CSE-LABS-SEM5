#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAC(a,b) a+b

typedef struct params{
    int key;
    enum { is_int, is_float, is_char } type;
    union {
        int ival;
        float fval;
        char cval;
    } val;
}params;

params parameters(){}

int getIntParam(params p, int k){

}

pid_t createProc(void *callback(params), int c, ...){
    pid_t pid;
    params argv;
    va_list args;
    va_start(args, c);
    pid = fork();
    if (pid == -1){
        perror("Child not created");
        exit(-1);
    }
    else if (pid == 0){
        callback(argv);
        exit(0);
    }
    return pid;
}