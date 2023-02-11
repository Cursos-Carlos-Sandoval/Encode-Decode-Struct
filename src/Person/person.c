#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extract_name(Person *person, char *buffer) {
	errno_t err = strncpy_s(buffer, ARRAY_MAX_SIZE, person->name, _TRUNCATE);
	if (err != 0) raise_error("TEXT_ENCODER: A problem occurred extracting the name");
}

void extract_address(Person *person, char *buffer) {
	errno_t err = strncpy_s(buffer, ARRAY_MAX_SIZE, person->address, _TRUNCATE);
	if (err != 0) raise_error("TEXT_ENCODER: A problem occurred extracting the address");
}
