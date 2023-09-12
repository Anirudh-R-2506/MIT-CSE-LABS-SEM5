#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct param{
    int a;
    int b;
} param;

void* summation(void* p){
    param* args = (param*) p;
    return (void*) args->a + args->b;
}

int main(){
    int a,b,sum;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    param args;
    args.a = a;
    args.b = b;
    pthread_t th;
    pthread_create(&th, 0, &summation, &args);
    pthread_join(th, (void**) &sum);
    printf("Sum: %d\n", sum);
}