CC = gcc
INC = -lncursesw
WARN = -Wall -Wextra

all: board.c board.h gol.c logic.c logic.h
	$(CC) $(WARN) gol.c board.c logic.c -g $(INC) -o gameoflife
