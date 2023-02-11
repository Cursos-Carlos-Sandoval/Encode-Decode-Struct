#include "encoder.h"
#include "../File/file.h"
#include "../Person/person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void raise_error(char *message) {
	fprintf(stderr, "%s", message);
	exit(EXIT_FAILURE);
}

void person_to_text(Person *person, char filename[]) {
	FILE *file = open_file(filename, "w");

	char buffer[ARRAY_MAX_SIZE];

	extract_name(person, buffer);
	write_buffer(buffer, file);

	extract_address(person, buffer);
	write_buffer(buffer, file);

	write_integer(person->age, file);
	write_float(person->height, file);

	fclose(file);
	return;
}
