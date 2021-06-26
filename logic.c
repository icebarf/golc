#include "logic.h"
#include "board.h"

/*nb_stat **init_nb_stats() {
    nb_stat cell_nb_stats[LENGTH_B][WIDTH_B] = calloc(LENGTH_B * WIDTH_B,
sizeof(nb_stat)); return cell_nb_stats;
}*/

extern nb_stat cell_nb_stats[LENGTH_B][WIDTH_B];
bool life_board_init[LENGTH_B][WIDTH_B] = {false};
bool life_board_next[LENGTH_B][WIDTH_B] = {false};
bool life_board_mid[LENGTH_B][WIDTH_B] = {false};

/* void rid_stats(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
 * free(cell_nb_stats); } */

/* Board has 4 corners
 * c1 = first element of first row
 * c2 = last element of first row
 * c3 = first element of last row
 * c4 = last element of last row
 */

void handle_c1(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    // Checks & Sets cell to the right of first cell
    if (life_board_init[0][1] == CL_ALIVE) {
        cell_nb_stats[0][0].alive++;
    } else {
        cell_nb_stats[0][0].dead++;
    }

    // Checks & Sets cell to the bottom of first cell
    if (life_board_init[1][0] == CL_ALIVE) {
        cell_nb_stats[0][0].alive++;
    } else {
        cell_nb_stats[0][0].dead++;
    }

    // Chceks & Sets cell to the bottom right of first cell
    if (life_board_init[1][1] == CL_ALIVE) {
        cell_nb_stats[0][0].alive++;
    } else {
        cell_nb_stats[0][0].dead++;
    }
}

void handle_c2(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    // Check & Sets cell to the left of last cell
    if (life_board_init[0][WIDTH_B - 2] == CL_ALIVE) {
        cell_nb_stats[0][WIDTH_B - 1].alive++;
    } else {
        cell_nb_stats[0][WIDTH_B - 1].dead++;
    }
    // Check & Sets cell to the bottom of last cell
    if (life_board_init[1][WIDTH_B - 1] == CL_ALIVE) {
        cell_nb_stats[0][WIDTH_B - 1].alive++;
    } else {
        cell_nb_stats[0][WIDTH_B - 1].dead++;
    }

    // Check & Sets cell to the bottom left of last cell
    if (life_board_init[1][WIDTH_B - 2] == CL_ALIVE) {
        cell_nb_stats[0][WIDTH_B - 1].alive++;
    } else {
        cell_nb_stats[0][WIDTH_B - 1].dead++;
    }
}

void handle_c3(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    // Check & Sets cell to the left of last cell
    if (life_board_init[LENGTH_B - 1][1] == CL_ALIVE) {
        cell_nb_stats[LENGTH_B - 1][0].alive++;
    } else {
        cell_nb_stats[LENGTH_B - 1][0].dead++;
    }

    // Check & Sets cell to the top of last row's first
    if (life_board_init[LENGTH_B - 2][0] == CL_ALIVE) {
        cell_nb_stats[LENGTH_B - 1][0].alive++;
    } else {
        cell_nb_stats[LENGTH_B - 1][0].dead++;
    }

    // Check & Sets cell to the top right of last row's cell
    if (life_board_init[LENGTH_B - 2][1] == CL_ALIVE) {
        cell_nb_stats[LENGTH_B - 1][0].alive++;
    } else {
        cell_nb_stats[LENGTH_B - 1][0].dead++;
    }
}

void handle_c4(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    // Check & Sets cell to the left of last cell
    if (life_board_init[LENGTH_B - 1][WIDTH_B - 2] == CL_ALIVE) {
        cell_nb_stats[LENGTH_B - 1][WIDTH_B - 1].alive++;
    } else {
        cell_nb_stats[LENGTH_B - 1][WIDTH_B - 1].dead++;
    }

    // Check & Sets cell to the top of last row's last cell
    if (life_board_init[LENGTH_B - 2][WIDTH_B - 1] == CL_ALIVE) {
        cell_nb_stats[LENGTH_B - 1][WIDTH_B - 1].alive++;
    } else {
        cell_nb_stats[LENGTH_B - 1][WIDTH_B - 1].dead++;
    }

    // Check & Sets cell to the top left of last row's cell
    if (life_board_init[LENGTH_B - 2][WIDTH_B - 2] == CL_ALIVE) {
        cell_nb_stats[LENGTH_B - 1][WIDTH_B - 1].alive++;
    } else {
        cell_nb_stats[LENGTH_B - 1][WIDTH_B - 1].dead++;
    }
}

void handle_row1(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    for_width {
        // Handle element to the right
        if (life_board_init[0][j + 1] == CL_ALIVE) {
            cell_nb_stats[0][j].alive++;
        } else {
            cell_nb_stats[0][j].dead++;
        }
        // Handle element to the left
        if (life_board_init[0][j - 1] == CL_ALIVE) {
            cell_nb_stats[0][j].alive++;
        } else {
            cell_nb_stats[0][j].dead++;
        }
        // Handle element on bottom
        if (life_board_init[1][j] == CL_ALIVE) {
            cell_nb_stats[0][j].alive++;
        } else {
            cell_nb_stats[0][j].dead++;
        }
        // Handle element on bottom right
        if (life_board_init[1][j + 1] == CL_ALIVE) {
            cell_nb_stats[0][j].alive++;
        } else {
            cell_nb_stats[0][j].dead++;
        }
        // Handle element on bottom left
        if (life_board_init[1][j - 1] == CL_ALIVE) {
            cell_nb_stats[0][j].alive++;
        } else {
            cell_nb_stats[0][j].dead++;
        }
    }
}


void handle_col0(int row, int col, nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    /* Handle case for top elements */
    if (life_board_init[row - 1][col] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for top right elements */
    if (life_board_init[row - 1][col + 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for right element */
    if (life_board_init[row][col + 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for bottom element */
    if (life_board_init[row + 1][col] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for bottom right element */
    if (life_board_init[row + 1][col + 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
}

void handle_cols(int row, int col, nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    /* Handle case for top element */
    if (life_board_init[row - 1][col] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for top left element */
    if (life_board_init[row - 1][col - 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for top right element */
    if (life_board_init[row - 1][col + 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for left element */
    if (life_board_init[row][col - 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for right element */
    if (life_board_init[row][col + 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for bottom element */
    if (life_board_init[row + 1][col] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for bottom left element */
    if (life_board_init[row + 1][col - 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for bottom right element */
    if (life_board_init[row + 1][col + 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
}

void handle_coll(int row, int col, nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    /* Handle case for element on top */
    if (life_board_init[row - 1][col] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for element on top left */
    if (life_board_init[row - 1][col - 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for element on left */
    if (life_board_init[row][col - 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for element on bottom */
    if (life_board_init[row + 1][col] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
    /* Handle case for element on bottom left */
    if (life_board_init[row + 1][col - 1] == CL_ALIVE) {
        cell_nb_stats[row][col].alive++;
    } else {
        cell_nb_stats[row][col].dead++;
    }
}

void handle_row_last(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    for_width {
        /* Handle element to the left */
        if (life_board_init[LENGTH_B - 1][j - 1] == CL_ALIVE) {
            cell_nb_stats[LENGTH_B - 1][j].alive++;
        } else {
            cell_nb_stats[LENGTH_B - 1][j].dead++;
        }
        /* Handle element to the right */
        if (life_board_init[LENGTH_B - 1][j + 1] == CL_ALIVE) {
            cell_nb_stats[LENGTH_B - 1][j].alive++;
        } else {
            cell_nb_stats[LENGTH_B - 1][j].dead++;
        }
        /* Handle element to the top */
        if (life_board_init[LENGTH_B - 2][j] == CL_ALIVE) {
            cell_nb_stats[LENGTH_B - 1][j].alive++;
        } else {
            cell_nb_stats[LENGTH_B - 1][j].dead++;
        }
        /* Handle element to the top left */
        if (life_board_init[LENGTH_B - 2][j - 1] == CL_ALIVE) {
            cell_nb_stats[LENGTH_B - 1][j].alive++;
        } else {
            cell_nb_stats[LENGTH_B - 1][j].dead++;
        }
        /* Handle element to the top right */
        if (life_board_init[LENGTH_B - 2][j + 1] == CL_ALIVE) {
            cell_nb_stats[LENGTH_B - 1][j].alive++;
        } else {
            cell_nb_stats[LENGTH_B - 1][j].dead++;
        }
    }
}

/* Function sets the first corner, second corner and the elements in between */
void handle_frow(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    for_length {
        if (i == 0) {
            handle_c1(cell_nb_stats);
            continue;
        }
        if (i == 1) {
            handle_row1(cell_nb_stats);
            i += WIDTH_B - 3;
            continue;
        }
        if (i == WIDTH_B - 1) {
            handle_c2(cell_nb_stats);
            continue;
        }
    }
}

/* Function sets all rows except the first and last row */
void handle_rows(int row, int col, nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    /* Handle case for cells on left edge */
    if (col == 0) {
        handle_col0(row, col, cell_nb_stats);
    }
    /* Handle case for cells in between edges */
    if (col > 0 && col < WIDTH_B - 1) {
        handle_cols(row, col, cell_nb_stats);
    }
    /* Handle case for cells on right edge */
    if (col == WIDTH_B - 1) {
        handle_coll(row, col, cell_nb_stats);
    }
}

/* Function sets the last row using row_last, c3 and c4. */
void handle_lrow(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    for_length {
        if (i == 0) {
            handle_c3(cell_nb_stats);
            continue;
        }
        if (i == 1) {
            handle_row_last(cell_nb_stats);
            i += WIDTH_B - 3;
            continue;
        }
        if (i == WIDTH_B - 1) {
            handle_c4(cell_nb_stats);
            continue;
        }
    }
}

void set_cell_status(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    for_length {
        for_width {
            if (life_board_init[i][j] == CL_ALIVE) {
                cell_nb_stats[i][j].status = CL_ALIVE;
            } else {
                cell_nb_stats[i][j].status = CL_DEAD;
            }
        }
    }
}

void set_neighbor_count(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    for_length {
        for_width {
            if (i == 0) {
                handle_frow(cell_nb_stats);
                break;
            }
            if ((i > 0) && (i < LENGTH_B - 1)) {
                handle_rows(i, j, cell_nb_stats);
            }
            if (i == LENGTH_B - 1) {
                handle_lrow(cell_nb_stats);
            }
        }
    }
}

void calculate_next_gen(nb_stat cell_nb_stats[LENGTH_B][WIDTH_B]) {
    for_length {
        for_width {
            if (cell_nb_stats[i][j].status == CL_ALIVE) {
                /* GOL Rule: Any alive cell with 0 or 1 neighbor dies */
                if (cell_nb_stats[i][j].alive < 2) {
                    life_board_mid[i][j] = CL_DEAD;
                }
                /* GOL Rule: Any alive cell with 2 or 3 neighbors stays alive */
                else if ((cell_nb_stats[i][j].alive >= 2)
                         && (cell_nb_stats[i][j].alive < 4)) {
                    life_board_mid[i][j] = CL_ALIVE;
                }
                /* GOL Rule: Any alive cell with more than 3 neighbors dies */
                else if (cell_nb_stats[i][j].alive > 3) {
                    life_board_mid[i][j] = CL_DEAD;
                }
            }
            /* GOL Rule: Any dead cell with exactly 3 neighbors will come alive
             */
            else if (cell_nb_stats[i][j].status == CL_DEAD) {
                if (cell_nb_stats[i][j].alive == 3) {
                    life_board_mid[i][j] = CL_ALIVE;
                }
            }
        }
    }
}