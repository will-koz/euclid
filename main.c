#include <stdio.h>
#include <stdlib.h>

#include "main.h"

void algo (int x, int y) {
	// Assumes that x is larger

	int rem = x % y;
	int q = x / y;
	printf("%d = (%d * %d) + %d", x, y, q, rem);
	if (rem != 0) {
		printf("\t| %d - (%d * %d) = %d", x, y, q, rem);
	}
	printf("\n");
	if (rem != 0) {
		algo(y, rem);
	}
}

int main (int argc, const char **argv) {
	if (argc != 3) {
		printf("Incorrect number of arguments.\n");
		return 1;
	}

	int x = atoi(argv[1]);
	int y = atoi(argv[2]);

	if (x == 0 || y == 0) {
		printf("Error parsing arguments. (Arguments can't be 0.)\n");
		return 1;
	}

	if (y > x) {
		int tmp = y;
		y = x;
		x = tmp;
	}

	algo (x, y);

	return 0;
}
