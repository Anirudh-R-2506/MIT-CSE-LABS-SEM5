#include "pipe.h"

int main(){
    int n;
    while (1){
        printf("Enter 1 to read, 0 to show: ");
        scanf("%d", &n);
        if (n == 0){
            show();
            continue;
        }
        int d;
        switch ((d = enqueue(n))){
            case 1:
                printf("Unable to read\n");
                break;
            case 2:
                printf("Underflow");
                break;
            default:
                printf("Read: %d\n", d);
                break;
        }
    }
}