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

/* Cell neighbor stats initializer and destructor */
nb_stat **init_nb_stats();
void rid_stats(nb_stat **cell_nb_stats);

/* Handlers for corners of the board. Should be used internally */
void handle_c1(nb_stat **cell_nb_stats);
void handle_c2(nb_stat **cell_nb_stats);
void handle_c3(nb_stat **cell_nb_stats);
void handle_c4(nb_stat **cell_nb_stats);

/* Row handlers. */
void handle_row1(nb_stat **cell_nb_stats);
void handle_frow(nb_stat **cell_nb_stats); /*caller of row1 and c1 and c2 */
void handle_lrow(nb_stat **cell_nb_stats);
void handle_rows(int i, nb_stat **cell_nb_stats); /* To be implemented */

/* Sets the stats of each cell's neighbor count and aliveness of a cell. */
void set_neighbors(nb_stat **cell_nb_stats);

/* note: Aliveness of a cell is to be implemented yet in the actual 
 * implementations of these functions. Should probably do it tomorrow */
