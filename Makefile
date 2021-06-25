CC = gcc
INC = -lncursesw
WARN = -Wall -Wextra

all: board.c board.h
	$(CC) $(WARN) board.c $(INC) -o board
