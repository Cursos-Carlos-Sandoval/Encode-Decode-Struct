#include "./Menu/menu.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	long value = main_menu();
	if (value == 1) {
		encoder_menu();
	} else {
		decoder_menu();
	}

	return EXIT_SUCCESS;
}
