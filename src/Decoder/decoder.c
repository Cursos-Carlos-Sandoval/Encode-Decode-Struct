#include "decoder.h"
#include "../File/file.h"
#include "../Person/person.h"
#include "../Utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

void print_text(char filename[]) {
	FILE *file = open_file(filename, "r");

	char buffer[ARRAY_MAX_SIZE];
	printf("Print from plain text file: \n\n");
	do {
		clean_buffer(buffer);
		char *ref = fgets(buffer, ARRAY_MAX_SIZE, file);
		if (ref == NULL) continue;

		switch (*ref) {
			case '\0':
				printf("\n");
				break;
			default:
				printf("%s", ref);
				break;
		}

	} while (!feof(file));

	fclose(file);
}

void print_binary(char filename[]) {
	FILE *file = open_file(filename, "rb");

	printf("Print from binary file: \n\n");
	read_text_binary(file); // Name
	read_text_binary(file); // Address
	read_unsigned_short(file); // Age
	read_float(file); // Height

	fclose(file);
}
