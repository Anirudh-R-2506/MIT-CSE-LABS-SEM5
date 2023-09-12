#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct param{
    int n;
    int* arr;
} param;

void* fibonacci(void* p){
    param* args = (param*) p;
    int i = 2, f = 0, s = 1, next = f + s;
    args->arr[0] = 0;
    args->arr[1] = 1;
    for(i; i<args->n; i++){
        args->arr[i] = next;
        f = s;
        s = next;
        next = f + s;
    }
    return (void *) args;
}

int main(){
    int n;
    printf("Enter limit: ");
    scanf("%d", &n);
    param args;
    args.n = n;
    args.arr = (int*) malloc(n * sizeof(int));
    pthread_t th;
    pthread_create(&th, 0, &fibonacci, &args);
    pthread_join(th, (void **) &args);
    for (int i = 0; i<n; i++){
        printf("%d ", args.arr[i]);
    }
    printf("\n");
}