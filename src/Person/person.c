#include "../Utils/utils.h"
#include "person.h"
#include <stdlib.h>
#include <string.h>

void extract_name(Person *person, char *buffer) {
	char *dest = strncpy(buffer, person->name, ARRAY_MAX_SIZE);
	if (dest == NULL) raise_error("PERSON_EXTRACTOR: A problem occurred extracting the name\n");
}

void extract_address(Person *person, char *buffer) {
	char *dest = strncpy(buffer, person->address, ARRAY_MAX_SIZE);
	if (dest == NULL) raise_error("PERSON_EXTRACTOR: A problem occurred extracting the name\n");
}
