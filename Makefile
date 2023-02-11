CC = gcc
CFLAGS = -Wall -g
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj

$(BIN_DIR)/main: $(OBJ_DIR)/main.o $(OBJ_DIR)/encoder.o $(OBJ_DIR)/file.o $(OBJ_DIR)/person.o
	$(CC) $(CFLAGS) $(BIN_DIR)/main -o $(SRC_DIR)/main.c

$(OBJ_DIR)/main.o: $(OBJ_DIR)/encoder.o $(OBJ_DIR)/file.o $(OBJ_DIR)/person.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c



$(OBJ_DIR)/person.o: $(OBJ_DIR)/person.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/person.c
