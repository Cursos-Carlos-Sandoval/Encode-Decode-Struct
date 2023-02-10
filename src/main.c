#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

int main() {
	Person p1;
	strncpy(p1.name, "Carlos Sandoval", ARRAY_MAX_SIZE);
	strncpy(p1.address, "498 Bayberry St. Goshen", ARRAY_MAX_SIZE);
	p1.age = 19;
	p1.height = 1.73;

	return EXIT_SUCCESS;
}