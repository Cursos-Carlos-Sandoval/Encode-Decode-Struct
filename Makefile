CC = gcc
CFLAGS = -Wall -g
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj

main: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) $(BIN_DIR)/main -o $(SRC_DIR)/main.c