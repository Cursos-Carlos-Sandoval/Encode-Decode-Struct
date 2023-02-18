#include "./Menu/menu.h"
#include "./Utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	// No flag defined - Encode flag
	if (argc < 2 || strcmp(argv[1], "--encode") == 0 || strcmp(argv[1], "-e") == 0) {
		printf("Start the encode menu...\n");
		encoder_menu();
		return EXIT_SUCCESS;
	}

	if (strcmp(argv[1], "--decode") == 0 || strcmp(argv[1], "-d") == 0) {
		// No path as argument
		if (argc < 3) {
			raise_error("Path to invalid target file\n");
		}

		printf("Start the decode menu...\n");
		decoder_menu(argv[2]);
		return EXIT_SUCCESS;
	}

	raise_error("Please indicate the operation to perform, use: --encode or --decode\n");
	return EXIT_FAILURE;
}
