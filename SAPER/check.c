#include <stdio.h>
#include <stdlib.h>
#include "check.h"

void printboard(int x, int y, char board[x][y]) {
    printf("      ");
    for(int i=0; i<x; i++) {
        printf("%-3d ", i);
    }
    printf("\n    -");
    for(int i=0; i<x; i++) {
        printf("----");
    }
    printf("\n");
    for(int i = 0; i<x; i++) {
        printf("%-3d | ", i);
        for(int j = 0; j<y; j++) {
            printf("%-3c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void check_space(int x, int y, char p_board[x][y], char s_board[x][y], int px, int py, int *pola, bool *gra, bool *wygrana, int first) {
    if (px < 0 || px >= x || py < 0 || py >= y || (p_board[px][py] != '#' && p_board[px][py] != 'F')) {
        return;
    } else if(s_board[px][py] == 'B' && first == 1) {
        p_board[px][py] = 'B';
        *wygrana = false;
        *gra = false;
        return;
    } else if (s_board[px][py] != '0' && s_board[px][py] != 'B') {
        p_board[px][py] = s_board[px][py];
        *pola -= 1;
        return;
    } else if (s_board[px][py] == '0') {
        p_board[px][py] = '0';
        *pola -= 1;
        int pola_wokol[4][2] = {{px-1, py}, {px, py-1}, {px, py+1}, {px+1, py}};
        for(int i=0; i<4; i++) {
            check_space(x, y, p_board, s_board, pola_wokol[i][0], pola_wokol[i][1], pola, gra, wygrana, 1);
        }
        return;
    }
    return;
}