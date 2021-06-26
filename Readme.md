# Conway's Game of Life

This is an implementation of Conway's game of life in C. It is a zero player game about cellular evolution on the basis of some predefined rules.
More can be read about this [here](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

## Rules

The rules of this game are simple

-   Any live cell with fewer than two live neighbours dies, as if by underpopulation.
-   Any live cell with two or three live neighbours lives on to the next generation.
-   Any live cell with more than three live neighbours dies, as if by overpopulation.
-   Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

## About Implementation

This is a very barebones but working implementation of Game of life. Graphics are to be implemented soon along with a load/save system
for initial game states which you may find interesting.

If you have any suggestions regarding code quality and improvements to be made and such, then please let me know by creating an issue on github.

## Building

- Make sure ncurses library is installed

- Clone the repository at a desired location

- cd golc

- make

Run the game using `./gameoflife`


## TODO List
Build a data structure to store board state     -           [/]

Pretty print the board to terminal              -           [/]

Given a starting board state, calculate next    -           [/]

Run the game forever                            -           [/]

Implement Graphics using SDL2 or equivalent     -           [ ]

--------------------------------------------------------------

Save interesting start pos to files and add load-and-save   []

--------------------------------------------------------------

Legend

[/]     -   Done

[ ]      -   To Be Implemented

[x]     -   Not willing to do/ To be done at a later time.