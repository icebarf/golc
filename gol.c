#include "logic.h"
#include <stdio.h>

extern bool life_board_init[LENGTH_B][WIDTH_B];
extern bool life_board_next[LENGTH_B][WIDTH_B];
extern bool life_board_mid[LENGTH_B][WIDTH_B];
extern bool life_board[LENGTH_B][WIDTH_B];

nb_stat cell_nb_stats[LENGTH_B][WIDTH_B] = {0};

int main() {
    srand(time(NULL));
    random_lb(LENGTH_B, WIDTH_B);
    copy_board(life_board_init, life_board);
    copy_board(life_board_next, life_board);

    while (1) {
        set_cell_status(cell_nb_stats);
        set_neighbor_count(cell_nb_stats);
        create_board(life_board_init);
        calculate_next_gen(cell_nb_stats);
        copy_board(life_board_init, life_board_mid);
        for_length {
            for_width {
                cell_nb_stats[i][j].alive = 0;
                cell_nb_stats[i][j].dead = 0;
                cell_nb_stats[i][j].status = 0;
            }
        }
    }
}