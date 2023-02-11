#ifndef PERSON
#define PERSON

#define ARRAY_MAX_SIZE 50

/**
 * Memory Representation of Person in Bytes:
 *     name        age       address      height
 * |----------||----------||----------||----------|
 * |  1 * 50  ||    2     ||  1 * 50  ||    4     |
 * |----------||----------||----------||----------|
 */
typedef struct person {
	char name[ARRAY_MAX_SIZE];
	char address[ARRAY_MAX_SIZE];
	unsigned short age;
	float height;
} Person

void extract_name(Person *person, char *buffer);
void extract_address(Person *person, char *buffer);

#endif // PERSON
