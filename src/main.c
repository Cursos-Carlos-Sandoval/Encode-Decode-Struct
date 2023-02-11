#include "./Person/person.h"
#include "./Encoder/encoder.h"
#include "./Decoder/decoder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	Person p1;
	strncpy(p1.name, "Carlos Sandoval", ARRAY_MAX_SIZE);
	strncpy(p1.address, "498 Bayberry St. Goshen", ARRAY_MAX_SIZE);
	p1.age = 19;
	p1.height = 1.73;

	person_to_text(&p1, "./data/persona.txt");
	person_to_binary(&p1, "./data/persona.bin");
	print_text("./data/persona.txt");

	return EXIT_SUCCESS;
}
