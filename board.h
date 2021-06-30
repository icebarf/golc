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

#define WIDTH_B    100
#define LENGTH_B   100

/* For Loop macros */
#define for_length      for(long int i = 0; i < LENGTH_B; i++)
#define for_width       for(long int j = 0; j < WIDTH_B; j++)

typedef bool bool_array[LENGTH_B];

bool_array *init_board();
void reset_board(bool (*life_board)[LENGTH_B]);
void random_lb(int length_b, int width_b, bool (*life_board)[LENGTH_B]);
void copy_board(bool (*dest)[LENGTH_B], bool (*src)[LENGTH_B]);
void create_board(bool (*life_board)[LENGTH_B]);
