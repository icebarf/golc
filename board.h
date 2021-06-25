#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <locale.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define WIDTH_B     50
#define LENGTH_B    50
#define CELL_AL     1       // Cell alive
#define CELL_DD     0       // Cell dead

bool life_board_init[LENGTH_B][WIDTH_B] = {false};

void random_lb(int length_b, int width_b);
void copy_board(bool dest[LENGTH_B][WIDTH_B], bool src[LENGTH_B][WIDTH_B]);
void create_board(bool life_board[LENGTH_B][WIDTH_B]);
