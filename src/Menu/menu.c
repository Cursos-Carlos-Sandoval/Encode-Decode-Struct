#include "./menu.h"
#include "../Decoder/decoder.h"
#include "../Encoder/encoder.h"
#include "../Person/person.h"
#include "../Utils/utils.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long main_menu() {
	char buffer[1024];
	long value;
	int success = 0;

	do {
		printf("Select an option:\n1.Encode\n2.Decode\nInput: ");
		// Read input - fail
		if (!fgets(buffer, 1024, stdin)) {
			raise_error("MENU: An error has occurred\n");
		}

		char *end_ptr;
		errno = 0;
		value = strtol(buffer, &end_ptr, 10);

		if (errno == ERANGE) {
			printf("This number is too small or too large\n");
		} else if (end_ptr == buffer) {
			printf("You have not registered a valid value\n");
		} else if (*end_ptr && *end_ptr != '\n') {
			printf("Value contains invalid characters for conversion\n");
		} else if (value < 1 || value > 2) {
			printf("\nInvalid option\n\n");
		} else {
			success = 1;
		}
	} while (!success);
	return value;
}

void encoder_menu() {
	char buffer[ARRAY_MAX_SIZE];
	Person person;

	printf("Create struct\nEnter the name: ");
	fgets(buffer, ARRAY_MAX_SIZE, stdin);
	// Clean buffer
	buffer[strcspn(buffer, "\r\n")] = 0;
	strncpy(person.name, buffer, ARRAY_MAX_SIZE);

	printf("Enter the address: ");
	fgets(buffer, ARRAY_MAX_SIZE, stdin);
	// Clean buffer
	buffer[strcspn(buffer, "\r\n")] = 0;
	strncpy(person.address, buffer, ARRAY_MAX_SIZE);

	printf("Enter the age: ");
	fgets(buffer, ARRAY_MAX_SIZE, stdin);
	char *end_ptr;
	person.age = (int) strtol(buffer, &end_ptr, 10);

	printf("Enter the height: ");
	fgets(buffer, ARRAY_MAX_SIZE, stdin);
	float height;
	sscanf(buffer, "%f", &height);
	person.height = height;

	printf("Filename (without extension): ");
	if (!fgets(buffer, ARRAY_MAX_SIZE, stdin)) {
		person_to_text(&person, "./data/person.txt");
		person_to_binary(&person, "./data/person.bin");
	} else {
		// Clean buffer
		buffer[strcspn(buffer, "\r\n")] = 0;

		char filename[2048] = "./data/";

		// Create path to text file
		strcat(filename, buffer);// ./data + buffer
		strcat(filename, ".txt");// ./data + buffer + .txt
		person_to_text(&person, filename);

		// Clear buffer
		strncpy(filename, "", 2048);

		// Create path to binary file
		strcat(filename, "./data/");
		strcat(filename, buffer);// ./data + buffer
		strcat(filename, ".bin");// ./data + buffer + .bin
		person_to_binary(&person, filename);
	}
	printf("File has been created!\n");
}

void decoder_menu() {
	char buffer[1024];
	printf("Path to file (with extension): ");
	if (!fgets(buffer, 1024, stdin)) {
		raise_error("MENU: Invalid input");
	} else {
		// Clean buffer
		buffer[strcspn(buffer, "\r\n")] = 0;

		// Get extension
		if (strstr(buffer, ".txt")) {
			print_text(buffer);
			return;
		}

		if (strstr(buffer, ".bin")) {
			print_binary(buffer);
			return;
		}

		raise_error("FILE: Invalid extension\n");
	}
}
