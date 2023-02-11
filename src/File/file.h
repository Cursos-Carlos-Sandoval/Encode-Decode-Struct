#ifndef FILE_HEADER
#define FILE_HEADER

#include <stdio.h>

FILE *open_file(char filename[], char mode[]);
void write_buffer(char *buffer, FILE *file);
void write_integer_text(char *buffer, int num, FILE *file);
void write_float_text(char *buffer, float num, FILE *file);
void write_unsigned_short_binary(unsigned short num, FILE *file);
void write_float_binary(float num, FILE *file);


#endif // FILE_HEADER
