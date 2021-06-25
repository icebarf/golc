#include "logic.h"
#include "board.h"

// Names to access elements of cell_neighbors array
enum names_n {T_Neighbor, TL_Neighbor, TR_Neighbor, 
                L_Neighbor, R_Neighbor, 
            B_Neighbor, BL_Neighbor, BR_Neighbor};

/* Need to calculate the states of cell_neighbors for that we have the initial
 * board state. We have that, next we need to implement to logic to check the
 * states of neighbors. Now we know the Neighbors are other elements of our
 * 2-D array. We can create two variants of cell_neighbors like we created two
 * board arrays. We first assign elements of each cell_neighbors to the initial
 * state of cells. Then we calculate which cell should be alive or dead
 * then we set the new statuses of cell_neighbors to the next board array
 * then print it. Rinse and repeat for whole game.
 * The we can maybe try to implement gui. Still undecided if wanna play with
 * ncurses and sleep(1) or maybe implement a opengl gui
*/

nb_stat **init_nb_stats(){
    nb_stat **cell_nb_stats = calloc(LENGTH_B, WIDTH_B);
    return cell_nb_stats;
}

void rid_stats(nb_stat **cell_nb_stats){
    free(cell_nb_stats);
}

/* Board is divided into 4 corners 
 * c1 = first element of first row
 * c2 = last element of first row
 * c3 = first element of last row
 * c4 = last element of last row
*/

void handle_c1(nb_stat **cell_nb_stats){
   // Checks & Sets cell to the right of first cell
   if(life_board_init[0][1] == 1) {cell_nb_stats[0][0].alive++;}
   else{cell_nb_stats[0][0].dead++;}

   // Checks & Sets cell to the bottom of first cell
   if(life_board_init[1][0] == 1) {cell_nb_stats[0][0].alive++;}
   else{cell_nb_stats[0][0].dead++;}

   // Chceks & Sets cell to the bottom right of first cell
   if(life_board_init[1][1] == 1) {cell_nb_stats[0][0].alive++;}
   else{cell_nb_stats[0][0].dead++;}

}

void handle_c2(nb_stat **cell_nb_stats) {
   // Check & Sets cell to the left of last cell
   if(life_board_init[0][WIDTH_B-2] == 1) {
       cell_nb_stats[0][WIDTH_B-1].alive++;
   }
   else{cell_nb_stats[0][WIDTH_B-1].dead++;}

   // Check & Sets cell to the bottom of last cell 
   if(life_board_init[1][WIDTH_B-1] == 1) {
       cell_nb_stats[0][WIDTH_B-1].alive++;
   }
   else{cell_nb_stats[0][WIDTH_B-1].dead++;}

   // Check & Sets cell to the bottom left of last cell
   if(life_board_init[1][WIDTH_B-2] == 1) {cell_nb_stats[0][WIDTH_B-1].alive++;}
   else{cell_nb_stats[0][WIDTH_B-1].dead++;}
}

void handle_c3(nb_stat **cell_nb_stats) {
   // Check & Sets cell to the left of last cell
   if(life_board_init[LENGTH_B-1][1] == 1) {cell_nb_stats[LENGTH_B-1][0].alive++;}
   else{cell_nb_stats[LENGTH_B-1][0].dead++;}

   // Check & Sets cell to the top of last row's first 
   if(life_board_init[LENGTH_B-2][0] == 1) {cell_nb_stats[LENGTH_B-1][0].alive++;}
   else{cell_nb_stats[LENGTH_B-1][0].dead++;}

   // Check & Sets cell to the top right of last row's cell
   if(life_board_init[LENGTH_B-2][1] == 1) {cell_nb_stats[LENGTH_B-1][0].alive++;}
   else{cell_nb_stats[LENGTH_B-1][0].dead++;}
}

void handle_c4(nb_stat **cell_nb_stats) {
   // Check & Sets cell to the left of last cell
   if(life_board_init[LENGTH_B-1][WIDTH_B-2] == 1) {cell_nb_stats[LENGTH_B-1][WIDTH_B-1].alive++;}
   else{cell_nb_stats[LENGTH_B-1][WIDTH_B-1].dead++;}

   // Check & Sets cell to the top of last row's last cell
   if(life_board_init[LENGTH_B-2][WIDTH_B-1] == 1) {cell_nb_stats[LENGTH_B-1][WIDTH_B-1].alive++;}
   else{cell_nb_stats[LENGTH_B-1][WIDTH_B-1].dead++;}

   // Check & Sets cell to the top left of last row's cell
   if(life_board_init[LENGTH_B-2][WIDTH_B-2] == 1) {cell_nb_stats[LENGTH_B-1][WIDTH_B-1].alive++;}
   else{cell_nb_stats[LENGTH_B-1][WIDTH_B-1].dead++;}
}

void handle_row1(nb_stat **cell_nb_stats){
   for_width{
      // Handle element to the right
      if(life_board_init[0][j+1] == 1){cell_nb_stats[0][j].alive++;}
      else{cell_nb_stats[0][j].dead++;}
      // Handle element to the left
      if(life_board_init[0][j-1] == 1){cell_nb_stats[0][j].alive++;}
      else{cell_nb_stats[0][j].dead++;}
      // Handle element on bottom
      if(life_board_init[1][j] == 1){cell_nb_stats[0][j].alive++;}
      else{cell_nb_stats[0][j].dead++;}
      // Handle element on bottom right
      if(life_board_init[1][j+1] == 1){cell_nb_stats[0][j].alive++;}
      else{cell_nb_stats[0][j].dead++;}
      // Handle element on bottom left
      if(life_board_init[1][j-1] == 1){cell_nb_stats[0][j].alive++;}
      else{cell_nb_stats[0][j].dead++;}
   }
}

// Function sets the first corner, second corner and the elements in between
void handle_frow(nb_stat **cell_nb_stats){
    for_length{
        if(i == 0){handle_c1(cell_nb_stats); continue;}
        if(i == 1) {handle_row1(cell_nb_stats); i+=WIDTH_B-3; continue;}
        if(i == WIDTH_B-1){handle_c2(cell_nb_stats); continue;}
   }
}

void handle_rows(int i, nb_stat **cell_nb_stats){
    if(life_board_init[i][1] == 1){
        /* Handle all cases for
         * xx
         * x*
         * xx
        */
        // IMPLEMENT HERE
    }
}

void set_neighbors(nb_stat **cell_nb_stats){
   for_length {
      for_width {
         if(i==0) {handle_frow(cell_nb_stats); break;}
         if((i>0) && (i<LENGTH_B-1)) {handle_rows(i, cell_nb_stats);}
         if(i==LENGTH_B-1) {handle_lrow(cell_nb_stats);}
      }
   }
}
