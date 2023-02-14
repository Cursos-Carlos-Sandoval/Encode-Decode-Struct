#ifndef FILE_HEADER
#define FILE_HEADER

#include <stdio.h>

/**
 * Method that opens a file with the specified name and mode. In case of failure,
 * it will throw an error and end the execution of the program. If it works, it returns
 * the corresponding file pointer.
 * @param filename Array of characters indicating the file name
 * @param mode The mode in which the file will be opened (@see fopen man)
 * @return FILE* pointer to file
 */
FILE *open_file(char filename[], char mode[]);

/**
 * Writes the contents of a buffer (of size ARRAY_MAX_SIZE) to the file.
 * @param buffer pointer to character array
 * @param file Pointer to target file
 */
void write_buffer(char *buffer, FILE *file);

/**
 * Gives an integer-to-text format to the num parameter, and stores it in the buffer,
 * then writes it to the file.
 * @param buffer Pointer to dest buffer
 * @param num Integer value to store
 * @param file Pointer to the file to which the integer is to be written
 */
void write_integer_text(char *buffer, int num, FILE *file);

/**
 * Formats the num parameter from float to text, stores it in the buffer, and then
 * writes it to the file.
 * @param buffer Pointer to dest buffer
 * @param num Floating point number to store
 * @param file Pointer to the file to which the float is to be written
 */
void write_float_text(char *buffer, float num, FILE *file);

/**
 * Stores the binary value of an unsigned short integer and writes it to the file
 * indicated by the pointer.
 * @param num Unsigned short number
 * @param file Pointer to the file to which the float is to be written
 */
void write_unsigned_short_binary(unsigned short num, FILE *file);

/**
 * Stores the binary value of a floating point number and writes it to the file
 * indicated by the pointer.
 * @param num float number
 * @param file Pointer to the file to which the float is to be written
 */
void write_float_binary(float num, FILE *file);

/**
 * Read the content of a file and process it as a string to print it to the console
 * @param file Pointer to the file to be processed
 */
void read_text_binary(FILE *file);

/**
 * Takes the 2 bytes following the cursor position, processes them as an integer,
 * and prints to the console.
 * @param file Pointer to the file to be processed
 */
void read_unsigned_short(FILE *file);

/**
 * Takes the 4 bytes following the cursor position, stores them in a buffer and
 * copies the contents of this array to a memory position corresponding to a variable
 * of type float to retrieve the value, prints this variable to the console.
 * @param file Pointer to the file to be processed
 */
void read_float(FILE *file);

#endif // FILE_HEADER
