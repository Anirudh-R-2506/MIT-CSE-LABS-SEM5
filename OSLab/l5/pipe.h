#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_SIZE 100
#define FNAME "queue.dat"

int enqueue();
int dequeue();
int getSize();
void show();

FILE *f = NULL;

int enqueue(int data){
    if (getSize() < MAX_SIZE){
        fseek(f, 0, SEEK_END);
        if(fprintf(f, "%d,", data) > 0)
            return 1;
        return 0;
    }
    else{
        return 2;
    }
}

int getSize(){
    char c;
    int i = 0;
    if (! f){
        f = fopen(FNAME, "a+");
        if (! f){
            fprintf(stderr, "Unable to open queue");
            exit(1);
        }
    }
    while((c = getc(f)) != EOF && c == ','){
        i++;
    }
    return i;
}

int dequeue(){
    if (getSize() < 0)
        return 2;
    char c;
    char data[500];
    int i = 0;
    while((c = getc(f)) != EOF && c != ','){
        data[i++] = c;
    }
    return atoi(data);
}

void show(){
    int s = getSize();
    if (s == 0)
        printf("Nothing to show\n");
    else{
        for(int j = 0; j < s; j++){
            char c;
            char data[500];
            int i = 0;
            while((c = getc(f)) != EOF && c != ','){
                data[i++] = c;
            }
            printf("%s\n", data);
        }
    }
}