#include "board.h"
#include <curses.h>
#include <locale.h>

bool life_board[LENGTH_B][WIDTH_B] = {false};

// Call "srand(time(NULL))" before calling this function
void random_lb(int length_b, int width_b) {
    for (int len = 0; len < length_b; len++){
        for (int wid = 0; wid < width_b; wid++){
            life_board[len][wid] = rand() % 2;
        }
    }
}

void copy_board(bool dest[LENGTH_B][WIDTH_B], bool src[LENGTH_B][WIDTH_B]) {
    for(int i = 0; i < LENGTH_B; i++) {
        for (int j = 0; j < WIDTH_B; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

// Create a window and print a bord
void create_board(bool board[LENGTH_B][WIDTH_B]) {
    initscr();
    noecho();
    cbreak();
    setlocale(LC_ALL, "");
    
    WINDOW *board_win = newwin(LENGTH_B+1, WIDTH_B+1, 0, 0);
    refresh();
    
    int i, j = 0;
    for (i = 0; i < LENGTH_B; i++){
        for (j = 0; j < WIDTH_B; j++){
            if (board[i][j] == 1){
                mvwprintw(board_win, i, j,"%s", "= ");
                wrefresh(board_win);
            }
            else {
                mvwprintw(board_win, i, j, " ");
                wrefresh(board_win);
            }
        }
        mvwprintw(board_win, i, j, "\n");
        wrefresh(board_win);
    }
    sleep(1);
}