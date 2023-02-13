CC = gcc
CFLAGS = -Wall -g
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj
DATA_DIR = ./data
MAIN_DEPENDENCIES = $(SRC_DIR)/Menu/menu.h \
	$(SRC_DIR)/main.c $(OBJ_DIR)/menu.o $(OBJ_DIR)/decoder.o $(OBJ_DIR)/encoder.o $(OBJ_DIR)/file.o $(OBJ_DIR)/person.o $(OBJ_DIR)/utils.o

build: clean $(BIN_DIR)/main
	./bin/main

$(BIN_DIR)/main: $(MAIN_DEPENDENCIES)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/main $(OBJ_DIR)/menu.o $(OBJ_DIR)/decoder.o $(OBJ_DIR)/encoder.o $(OBJ_DIR)/file.o $(OBJ_DIR)/person.o $(OBJ_DIR)/utils.o $(SRC_DIR)/main.c

$(OBJ_DIR)/menu.o: $(SRC_DIR)/Menu/menu.h $(SRC_DIR)/Person/person.h $(SRC_DIR)/Utils/utils.h $(SRC_DIR)/Encoder/encoder.h $(SRC_DIR)/Decoder/decoder.h
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/menu.o -c $(SRC_DIR)/Menu/menu.c

$(OBJ_DIR)/decoder.o: $(SRC_DIR)/Person/person.h $(SRC_DIR)/File/file.h $(SRC_DIR)/Decoder/decoder.h
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/decoder.o -c $(SRC_DIR)/Decoder/decoder.c

$(OBJ_DIR)/encoder.o: $(SRC_DIR)/Person/person.h $(SRC_DIR)/File/file.h $(SRC_DIR)/Encoder/encoder.h
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/encoder.o -c $(SRC_DIR)/Encoder/encoder.c

$(OBJ_DIR)/file.o: $(SRC_DIR)/Utils/utils.h $(SRC_DIR)/Encoder/encoder.h $(SRC_DIR)/File/file.h $(SRC_DIR)/File/file.c
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/file.o -c $(SRC_DIR)/File/file.c

$(OBJ_DIR)/person.o: $(SRC_DIR)/Utils/utils.h $(SRC_DIR)/Person/person.h $(SRC_DIR)/Person/person.c
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/person.o -c $(SRC_DIR)/Person/person.c

$(OBJ_DIR)/utils.o: $(SRC_DIR)/Person/person.h $(SRC_DIR)/Utils/utils.h $(SRC_DIR)/Utils/utils.c
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/utils.o -c $(SRC_DIR)/Utils/utils.c

.PHONY: clean_obj clean_data clean_bin clean
clean_obj:
	rm -rf $(OBJ_DIR)/*

clean_data:
	rm -rf $(DATA_DIR)/*

clean_bin:
	rm -rf $(BIN_DIR)/*

clean: clean_bin clean_data clean_obj
