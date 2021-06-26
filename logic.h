#pragma once
#include "board.h"

#define NEIGHBORS 8
#define CL_DEAD false
#define CL_ALIVE true

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
void rid_stats(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);

/* Handlers for corners of the board. Should be used internally */
void handle_c1(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);
void handle_c2(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);
void handle_c3(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);
void handle_c4(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);

/* Row handlers. */
void handle_row1(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);
void handle_frow(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]); /*caller of row1 and c1 and c2 */
void handle_col0(int row, int col, nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);
void handle_cols(int row, int col, nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);
void handle_coll(int row, int col, nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);
void handle_row_last(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]); 
void handle_lrow(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]); /*caller of rowl and c3 and c4 */
void handle_rows(int row, int col, nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]); 


/* Sets the stats of each cell's neighbor count and aliveness of a cell. */
void set_cell_status(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);
void set_neighbor_count(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);
void calculate_next_gen(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]);

/* note: Aliveness of a cell is to be implemented yet in the actual 
 * implementations of these functions. Should probably do it tomorrow */