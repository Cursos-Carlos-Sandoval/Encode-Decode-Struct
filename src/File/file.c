#include "file.h"
#include "../Encoder/encoder.h"
#include "../Utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *open_file(char filename[], char mode[])
{
	FILE *file = fopen(filename, mode);
	if (file == NULL)
		raise_error("FILE: An error occurred while opening the file\n");
	return file;
}

void write_buffer(char *buffer, FILE *file)
{
	size_t process_validator = fwrite(buffer, sizeof(char), ARRAY_MAX_SIZE, file);
	if (process_validator < ARRAY_MAX_SIZE)
		raise_error("FILE: An error occurred while writing buffer to the file\n");
	fputc('\n', file);
	clean_buffer(buffer);
}

void write_integer_text(char *buffer, int num, FILE *file)
{
	sprintf(buffer, "%d", num);
	write_buffer(buffer, file);
}

void write_float_text(char *buffer, float num, FILE *file)
{
	sprintf(buffer, "%.2f", num);
	write_buffer(buffer, file);
}

void write_unsigned_short_binary(unsigned short num, FILE *file)
{
	size_t process_validator = fwrite(&num, sizeof(unsigned short), 1, file);
	if (process_validator < 1)
		raise_error("FILE: An error occurred while writing unsigned short number to the file\n");
	fputc('\n', file);
}

void write_float_binary(float num, FILE *file)
{
	size_t process_validator = fwrite(&num, sizeof(float), 1, file);
	if (process_validator < 1)
		raise_error("FILE: An error occurred while writing float number to the file\n");
	fputc('\n', file);
}

void read_text_binary(FILE *file)
{
	// Get 50 bytes
	char buffer[ARRAY_MAX_SIZE];
	for (int i = 0; i < ARRAY_MAX_SIZE; i++) {
		buffer[i] = fgetc(file);
	}
	printf("%s", buffer);

	// Manage \n
	printf("%c", fgetc(file));
}

void read_unsigned_short(FILE *file)
{
	// Get 2 bytes
	char buffer[sizeof(unsigned short)];
	for (int i = 0; i < sizeof(unsigned short); i++) {
		buffer[i] = fgetc(file);
	}
	printf("%d", (unsigned short)*buffer);

	// Manage \n
	printf("%c", fgetc(file));
}

void read_float(FILE *file)
{
	// Get 4 bytes
	char buffer[sizeof(float)];
	float num;
	for (int i = 0; i < sizeof(float); i++) {
		buffer[i] = fgetc(file);
	}

	memcpy(&num, buffer, sizeof(float));
	printf("%.2f", num);

	// Manage \n
	printf("%c", fgetc(file));
}
