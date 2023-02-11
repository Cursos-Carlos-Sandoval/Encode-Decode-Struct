#include "decoder.h"
#include "../File/file.h"
#include "../Person/person.h"
#include <stdio.h>
#include <stdlib.h>

void print_text(char filename[]) {
	FILE *file = open_file(filename, "r");

	char buffer[ARRAY_MAX_SIZE];

	do {
		char *ref = fgets(buffer, ARRAY_MAX_SIZE, file);
		if (ref == NULL) continue;

		switch (*ref) {
			case '\0':
				printf("\n");
				break;
			default:
				printf("%s", ref);
		}

	} while (!feof(file));

	fclose(file);
}

void print_binary(char filename[]) {
}
