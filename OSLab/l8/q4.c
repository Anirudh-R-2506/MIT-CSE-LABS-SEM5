#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct param{
    int *oArr;
    int *eArr;
    int oNum;
    int eNum;
} param;

void* oddSummation(void* p){
    param* args = (param*) p;
    int s = 0;
    for(int i = 0; i<args->oNum; i++)
        s += args->oArr[i];
    return (void*) s;
}

void* evenSummation(void* p){
    param* args = (param*) p;
    int s = 0;
    for(int i = 0; i<args->eNum; i++)
        s += args->eArr[i];
    return (void*) s;
}

int main(){
    int n,o,e,buf;
    param args;
    printf("Enter limit: ");scanf("%d", &n);
    args.eNum = 0;args.oNum = 0;
    args.eArr = (int*)malloc(n * sizeof(int));args.oArr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i<n; i++){
        scanf("%d", &buf);
        if (buf%2 == 0)
            args.eArr[args.eNum++] = buf;
        else
            args.oArr[args.oNum++] = buf;
    }
    pthread_t th[2];
    pthread_create(&th[0], 0, &oddSummation, &args);
    pthread_create(&th[1], 0, &evenSummation, &args);
    pthread_join(th[0], (void**)&o);
    pthread_join(th[1], (void**)&e);
    printf("Odd Sum: %d\nEven Sum: %d\n", o, e);
}