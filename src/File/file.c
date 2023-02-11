#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *open_file(char filename[], char mode[]) {
	FILE *file = NULL;
	errno_t err = fopen_s(&file, filename, mode);
	if (err != 0 || file == NULL) raise_error("TEXT_ENCODER: An error occurred while opening the file");
}

void write_buffer(char *buffer, FILE *file) {
	size_t process_validator = fwrite(buffer, sizeof(char), ARRAY_MAX_SIZE, file);
	if (process_validator < ARRAY_MAX_SIZE) raise_error("TEXT_ENCODER: An error occurred while writing to the file");
	fputs("\n", file);
}

void write_integer(int num, FILE *file) {
	size_t process_validator = fwrite(&num, sizeof(int), 1, file);
	if (process_validator < ARRAY_MAX_SIZE) raise_error("TEXT_ENCODER: An error occurred while writing to the file");
	fputs("\n", file);
}

void write_float(float num, FILE *file) {
	size_t process_validator = fwrite(&num, sizeof(float), 1, file);
	if (process_validator < ARRAY_MAX_SIZE) raise_error("TEXT_ENCODER: An error occurred while writing to the file");
	fputs("\n", file);
}
