#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct param{
    int a;
    int b;
    int *arr;
    int cnt;
} param;

void* summation(void* p){
    param* args = (param*) p;
    int i,j,f,c=0;
    for(i = args->a; i<=args->b; i++){
        if (i == 1 || i == 0 || i % 2 == 0){
            continue;
        }
        f = 1;
        for(j = 3; j<=sqrt(i); j++){
            if (i%j == 0){
                f = 0;
                break;
            }
        }
        if (f == 1)
            args->arr[c++] = i;
    }
    args->cnt = c;
    return (void*) args;
}

int main(){
    int a,b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    int n = b - a;
    param args = { .a = a, .b = b, .arr = (int*)malloc(n * sizeof(int)) };
    pthread_t th;
    pthread_create(&th, 0, &summation, &args);
    pthread_join(th, (void**) &args);
    for(int i = 0; i<args.cnt; i++){
        printf("%d ", args.arr[i]);
    }
    printf("\n");
}