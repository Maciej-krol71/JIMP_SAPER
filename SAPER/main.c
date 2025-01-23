#include <stdio.h>
#include <stdlib.h>

#include "generate.h"
#include "check.h"

int main (int argc, char *argv[]) {
    int x, y, m;
    char tryb;
    printf("Podaj wymiary planszy na jakiej chcesz zagrac:\n");
    printf("l - latwa (9 x 9, 10 min)\ns - srednia(16 x 16, 40 min)\nt - trudna (16 x 30, 99 min)\nc - plansza wlasna\n");
    scanf("%c", &tryb);

    while(tryb!='l' && tryb!='s' && tryb!='t' && tryb!='c') {
        printf("Podano niepoprawny argument. Podaj wymiar jeszcze raz:\n");
        scanf("%c", &tryb);
    }

    if(tryb == 'l') {
        x = 9;
        y = 9;
        m = 10;
    } else if(tryb == 's') {
        x = 16;
        y = 16;
        m = 40;
    } else if(tryb == 't') {
        x = 16;
        y = 30;
        m = 99;
    } else if(tryb == 'c') {
        printf("Podaj ilosc wierszy: ");
        scanf("%d", &x);
        printf("Podaj ilosc kolumn: ");
        scanf("%d", &y);
        printf("Podaj ilosc min: ");
        scanf("%d", &m);
    }

    int start_x, start_y;
    printf("Podaj pole, z ktorego chcesz wystartowac (np. 5 4): ");
    scanf("%d %d", &start_x, &start_y);

    char p_board[x][y];
    char s_board[x][y];
    genboard(x, y, m, p_board, s_board, start_x, start_y);
    
    int pola = x*y - m;
    bool wygrana = true;
    bool gra = true;
    int px, py;
    char pt;

    check_space(x, y, p_board, s_board, start_x, start_y, &pola, &gra, &wygrana, 1);  

    printf("Wybierz czy chcesz postawic flage czy odslonic pole\n");
    printf("Aby postawic flage wpisz: f x_pola y_pola (np f 3 4)\n");
    printf("Aby odslonic pole wpisz: o x_pola y_pola (np o 2 3)\n");

    while(gra) {
        printboard(x, y, p_board);
        if(pola==0) {
            gra = false;
            break;
        }
        else {
            scanf("%c %d %d", &pt, &px, &py);
            if(pt == 'f' && p_board[px][py] == '#') {
                p_board[px][py] = 'F';
            } else if(pt == 'o') {
                check_space(x, y, p_board, s_board, px, py, &pola, &gra, &wygrana, 1);
            }
        }
    }

    if(wygrana) {
        printboard(x, y, s_board);
        printf("Gratulacje! Ukonczyles gre.\n");
    } else {
        printboard(x, y, s_board);
        printf("Niestety odrkyles mine.\n");
    }
}