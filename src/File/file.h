#ifndef FILE
#define FILE

#include <stdio.h>

FILE *open_file(char filename[], char mode[]);
void write_buffer(char *buffer, FILE *file);
void write_integer(int num, FILE *file);
void write_float(float num, FILE *file);

#endif // FILE
