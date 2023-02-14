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
} Person;

/**
 * The function copy the elements of the character array (Person.name) and copies them to a buffer
 * @param person Pointer to the person structure
 * @param buffer Pointer to destination array (must have a number of elements equal to ARRAY_MAX_SIZE)
 */
void extract_name(Person *person, char *buffer);

/**
 * The function copy the elements of the character array (Person.address) and copies them to a buffer
 * @param person Pointer to the person structure
 * @param buffer Pointer to destination array (must have a number of elements equal to ARRAY_MAX_SIZE)
 */
void extract_address(Person *person, char *buffer);

#endif // PERSON
