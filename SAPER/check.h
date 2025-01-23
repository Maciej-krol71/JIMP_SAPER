#include <stdbool.h>
#ifndef _CHECK_H
#define _CHECK_H

void printboard(int x, int y, char board[x][y]);
void check_space(int x, int y, char p_board[x][y], char s_board[x][y], int px, int py, int *pola, bool *gra, bool *wygrana, int first);

#endif