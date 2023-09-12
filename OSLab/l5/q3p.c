#include "pipe.h"

int main(){
    int n;
    while (1){
        printf("Enter number to write, 0 to show: ");
        scanf("%d", &n);
        if (n == 0){
            show();
            continue;
        }
        switch (enqueue(n)){
            case 0:
                printf("Succesfully written\n");
                break;
            case 1:
                printf("Unable to write\n");
                break;
            case 2:
                printf("Overflow\n");
                break;
        }
    }
}