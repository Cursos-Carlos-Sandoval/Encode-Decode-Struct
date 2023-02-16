#ifndef ENCODER
#define ENCODER

#include "../Person/person.h"

/**
 * Method in charge of converting each characteristic of an instance of the person
 * structure into plain text and writing it to a file named 'filename'
 * @param person
 * @param filename
 */
void person_to_text(Person *person, char filename[]);

/**
 * Method in charge of converting each characteristic of an instance of the person
 * structure into binary values and writing it to a file named 'filename'
 * @param person
 * @param filename
 */
void person_to_binary(Person *person, char filename[]);

#endif // ENCODER
