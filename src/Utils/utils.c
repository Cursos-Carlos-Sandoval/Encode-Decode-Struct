#include "../Person/person.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void raise_error(char *message)
{
	fprintf(stderr, "%s", message);
	exit(EXIT_FAILURE);
}

void clean_buffer(char *buffer)
{
	strncpy(buffer, "", ARRAY_MAX_SIZE);
}
