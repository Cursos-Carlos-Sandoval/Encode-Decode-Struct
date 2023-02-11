#include "file.h"
#include "../Encoder/encoder.h"
#include "../Utils/utils.h"
#include <stdlib.h>

FILE *open_file(char filename[], char mode[]) {
	FILE *file = fopen(filename, mode);
	if (file == NULL) raise_error("FILE: An error occurred while opening the file\n");
	return file;
}

void write_buffer(char *buffer, FILE *file) {
	size_t process_validator = fwrite(buffer, sizeof(char), ARRAY_MAX_SIZE, file);
	if (process_validator < ARRAY_MAX_SIZE) raise_error("FILE: An error occurred while writing buffer to the file\n");
	fputs("\n", file);
	clean_buffer(buffer);
}

void write_integer_text(char *buffer, int num, FILE *file) {
	sprintf(buffer, "%d", num);
	write_buffer(buffer, file);
}

void write_float_text(char *buffer, float num, FILE *file) {
	sprintf(buffer, "%.2f", num);
	write_buffer(buffer, file);
}

void write_unsigned_short_binary(unsigned short num, FILE *file) {
	size_t process_validator = fwrite(&num, sizeof(unsigned short), 1, file);
	if (process_validator < 1) raise_error("FILE: An error occurred while writing unsigned short number to the file\n");
	fputs("\n", file);
}

void write_float_binary(float num, FILE *file) {
	size_t process_validator = fwrite(&num, sizeof(float), 1, file);
	if (process_validator < 1) raise_error("FILE: An error occurred while writing float number to the file\n");
	fputs("\n", file);
}

void read_text(char *buffer, FILE *file) {
	clean_buffer(buffer);
	size_t process_validator = fread(buffer, sizeof(char), ARRAY_MAX_SIZE, file);
	if (process_validator < ARRAY_MAX_SIZE) raise_error("FILE: An error has occurred while reading the file");
}
