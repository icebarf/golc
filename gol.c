#include "logic.h"
#include <stdio.h>

extern bool life_board_init[LENGTH_B][WIDTH_B];
extern bool life_board_next[LENGTH_B][WIDTH_B];
extern bool life_board_mid[LENGTH_B][WIDTH_B];

int main() {
    /* Variable initialisers */
    bool(*life_board)[LENGTH_B] = init_board();
    bool(*life_board_init)[LENGTH_B] = init_board();
    bool(*life_board_mid)[LENGTH_B] = init_board();
    bool(*life_board_next)[LENGTH_B] = init_board();
    nb_stat(*cell_nb_stats)[LENGTH_B] = init_stats();

    /* Reset */
    reset_stats(cell_nb_stats);
    reset_board(life_board);
    reset_board(life_board_init);
    reset_board(life_board_mid);
    reset_board(life_board_next);

    srand(time(NULL));
    random_lb(LENGTH_B, WIDTH_B, life_board);
    copy_board(life_board_init, life_board);
    copy_board(life_board_next, life_board);

    while (1) {
        set_cell_status(cell_nb_stats, life_board_init);
        set_neighbor_count(cell_nb_stats, life_board_init);
        create_board(life_board_init);
        calculate_next_gen(cell_nb_stats, life_board_mid);
        copy_board(life_board_init, life_board_mid);
        reset_stats(cell_nb_stats);
    }
    rid_stats(cell_nb_stats);
}