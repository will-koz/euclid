#include <stdio.h>
#include <stdlib.h>

#include "main.h"

struct {
	int i;
	int j;

	int ival;
	int jval;
} linear_combo;

int algo (int x, int y) {
	// Assumes that x is larger

	// Print out the top information
	int rem = x % y;
	int q = x / y;
	printf("%d = (%d * %d) + %d", x, y, q, rem);
	if (rem != 0) printf("\t\t\t| %d - (%d * %d) = %d", x, y, q, rem);
	else printf("\n");
	printf("\n");

	// Get the next part of the linear combination
	int n = 0;
	if (rem != 0) n = algo(y, rem);
	else { return 0; }

	// If the next level is zero, set the linear combination to 1, 1
	if (n == 0) {
		linear_combo.i = 1;
		linear_combo.j = q;

		linear_combo.ival = x;
		linear_combo.jval = y;

		printf("%d =", rem);
		dump_combo();
	} else {
		printf("=");
		// Uncomment for a slightly more verbose explanation of what's going on:
		// printf("\t(%d * %d) - (%d * (%d - %d * %d)) =", linear_combo.i, linear_combo.ival,
		// 	linear_combo.j, x, y, q);

		linear_combo.i += linear_combo.j * q;
		linear_combo.jval = x;

		refactor();

		dump_combo();
	}

	return q;
}

void dump_combo () {
	printf("\t(%d * %d) - (%d * %d)\n", linear_combo.i, linear_combo.ival,
		linear_combo.j, linear_combo.jval);
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

	// If the combo is negative, reverse the order of the combination to make it more readable
	if (linear_combo.j <= 0) refactor();

	// Print out final answer:
	printf("\n(%d)(%d) - (%d)(%d)\n", linear_combo.i, linear_combo.ival,
		linear_combo.j, linear_combo.jval);

	return 0;
}

void refactor () {
	int tmp = linear_combo.j;
	int tmpval = linear_combo.jval;

	linear_combo.j = -linear_combo.i;
	linear_combo.jval = linear_combo.ival;

	linear_combo.ival = tmpval;
	linear_combo.i = -tmp;
}
