#ifndef UTILS
#define UTILS


/**
 * Method that allows executing the program to end immediately and print a message about the reason
 * @param message to print before finishing the execution
 */
void raise_error(char *message);

/**
 * Converts all items in the buffer to the null character
 * @param buffer Pointer to buffer (must have ARRAY_MAX_SIZE size)
 */
void clean_buffer(char *buffer);

#endif // UTILS
