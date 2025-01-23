#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generate.h"

int max(int a, int b) {
    if(a > b) {return a;}
    return b;
}

int min(int a, int b) {
    if(a < b) {return a;}
    return b;
}

void genboard(int x, int y, int m, char p_board[x][y], char s_board[x][y], int start_x, int start_y) {
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            s_board[i][j] = '#';
            p_board[i][j] = '#';
        }
    }

    srand(time(NULL));
    int m_count = 0;
    while(m_count < m) {
        int ran_x = rand() % x;
        int ran_y = rand() % y;
        if(s_board[ran_x][ran_y] != 'B' && (ran_x != start_x || ran_y != start_y)) {
            s_board[ran_x][ran_y] = 'B';
            m_count++;
        }
    }

    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            if(s_board[i][j] != 'B') {
                int B_count = 0;
                for(int q=max(0, i-1); q < min(x, i+2); q++) {
                    for(int p=max(0, j-1); p < min(y, j+2); p++) {
                        if(s_board[q][p] == 'B') {
                            B_count++;
                        }
                    }
                }
                s_board[i][j] = B_count + '0';
            }
        }
    }
}