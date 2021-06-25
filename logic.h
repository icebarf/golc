#pragma once
#include "board.h"

#define NEIGHBORS 8

/* For Loop macros */
#define for_length      for(long int i = 0; i < LENGTH_B; i++)
#define for_width       for(long int j = 0; j < WIDTH_B; j++)

struct cell_neighbor_stats {
    bool status;
    uint8_t dead;
    uint8_t alive;
};

typedef struct cell_neighbor_stats nb_stat;
