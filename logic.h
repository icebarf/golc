#pragma once
#include "board.h"

#define NEIGHBORS 8
#define CL_DEAD false
#define CL_ALIVE true

struct cell_neighbor_stats {
    bool status;
    uint8_t dead;
    uint8_t alive;
};
typedef struct cell_neighbor_stats nb_stat;
typedef nb_stat nb_stat_array[LENGTH_B];

/* Cell neighbor stats initializer and destructor */
nb_stat_array *init_stats();
void reset_stats(nb_stat (*cell_nb_stats)[LENGTH_B]);
void rid_stats(nb_stat (*cell_nb_stats)[LENGTH_B]);

/* Handlers for corners of the board. Should be used internally */
void handle_c1(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]);
void handle_c2(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]);
void handle_c3(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]);
void handle_c4(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]);

/* Row handlers. */
void handle_row1(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]);
void handle_frow(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]); /*caller of row1 and c1 and c2 */
void handle_col0(int row, int col, nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]);
void handle_cols(int row, int col, nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]);
void handle_coll(int row, int col, nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]);
void handle_row_last(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]); 
void handle_lrow(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]); /*caller of rowl and c3 and c4 */
void handle_rows(int row, int col, nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]); 


/* Sets the stats of each cell's neighbor count and aliveness of a cell. */
void set_cell_status(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]);
void set_neighbor_count(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_init)[LENGTH_B]);
void calculate_next_gen(nb_stat (*cell_nb_stats)[LENGTH_B], bool (*life_board_mid)[LENGTH_B]);