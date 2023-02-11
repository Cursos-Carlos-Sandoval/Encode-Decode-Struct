CC = gcc
CFLAGS = -Wall -g
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj

$(BIN_DIR)/main: $(SRC_DIR)/Person/person.h $(SRC_DIR)/Encoder/encoder.h $(SRC_DIR)/main.c $(OBJ_DIR)/encoder.o $(OBJ_DIR)/file.o $(OBJ_DIR)/person.o $(OBJ_DIR)/utils.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/main $(OBJ_DIR)/encoder.o $(OBJ_DIR)/file.o $(OBJ_DIR)/person.o $(OBJ_DIR)/utils.o $(SRC_DIR)/main.c

$(OBJ_DIR)/encoder.o: $(SRC_DIR)/Person/person.h $(SRC_DIR)/File/file.h $(SRC_DIR)/Encoder/encoder.h
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/encoder.o -c $(SRC_DIR)/Encoder/encoder.c

$(OBJ_DIR)/file.o: $(SRC_DIR)/Utils/utils.h $(SRC_DIR)/Encoder/encoder.h $(SRC_DIR)/File/file.h $(SRC_DIR)/File/file.c
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/file.o -c $(SRC_DIR)/File/file.c

$(OBJ_DIR)/person.o: $(SRC_DIR)/Utils/utils.h $(SRC_DIR)/Person/person.h $(SRC_DIR)/Person/person.c
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/person.o -c $(SRC_DIR)/Person/person.c

$(OBJ_DIR)/utils.o: $(SRC_DIR)/Person/person.h $(SRC_DIR)/Utils/utils.h $(SRC_DIR)/Utils/utils.c
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/utils.o -c $(SRC_DIR)/Utils/utils.c

clean:
	rm -rf bin/* obj/*
