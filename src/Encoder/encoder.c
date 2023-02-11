#include "encoder.h"
#include "../File/file.h"
#include <stdio.h>

void person_to_text(Person *person, char filename[]) {
	FILE *file = open_file(filename, "w");

	char buffer[ARRAY_MAX_SIZE];

	extract_name(person, buffer);
	write_buffer(buffer, file);

	extract_address(person, buffer);
	write_buffer(buffer, file);

	write_integer_text(buffer, person->age, file);
	write_float_text(buffer, person->height, file);

	fclose(file);
}
