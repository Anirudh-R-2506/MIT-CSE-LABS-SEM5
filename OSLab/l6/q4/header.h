#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SIZE 3
#define MAX_MOVES SIZE*SIZE
int rows[] = {97, 98, 99};//a, b, c
int cols[] = {1, 2, 3};
int m;

typedef struct player{
    int id;
    char *name;
    int choice;//1 -> O; 2 -> X
} player;

typedef struct move{
    char currMove[2];
    char moveHistory[2][MAX_MOVES];
} move;

typedef struct game{
    player p1;
    player p2;
    int board[SIZE][SIZE];
} game;

int checkRow(int r){
    for(int i = 0; i < SIZE; i++){
        if (rows[i] == r)
            return 1;
    }
    return 0;
} 

int checkCol(int c){
    for(int i = 0; i < SIZE; i++){
        if (cols[i] == c)
            return 1;
    }
    return 0;
}

int checkGame(game g){
    int i = 0, j = 0;
    for(i; i<SIZE; i++){
        for(j; j<SIZE; j++){

        }
    }
}

int checkWinner(game g){

}

int playMove(game g, move m, int p){
    char row = m.currMove[0];
    int c = m.currMove[1] - '0';
    if (checkCol(c) == 0 || checkRow(row) == 0){
        fprintf(stderr, "Invalid row or column");
        return 0;
    }
    int r = row - '0' - 97;
    c -= 1;
    g.board[r][c] = (p == 0) ? g.p1.choice : g.p2.choice;
}

void printMoveHistory(game g, move m){
    int printer = 1;
    for(int i = 0; i < MAX_MOVES; i++){
        if (printer % 2 != 0)
            printf("%s:\t", g.p1.name);
        else
            printf("%s:\t", g.p2.name);
        printf("%s\n", m.moveHistory[i]);
    }
}

void printBoard(game g){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            int sqr = g.board[i][j];
            if (sqr == 1)
                printf(" O");
            else if (sqr == 2)
                printf(" X");
            else
                printf(" -");
            if (j < SIZE - 1)
                printf(" |");
        }
        printf("____________\n");
    }
}
