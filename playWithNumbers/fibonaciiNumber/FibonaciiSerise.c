/**
*Name: Minhas Kamal (IIT, DU)
*Date:24.Feb.2013
**/

#include <stdio.h>

int main() {
	int a, b;

	printf("Enter first serial num: ");
	scanf("%d", &a);

	printf("Enter second serial num: ");
	scanf("%d", &b);

	int m, n;

	for (m = a; m <= b; m++) {
		long long int x = 0, y = 1, z;

		for (n = 1; n < m; n++) {
			z = y;
			y = x + y;
			x = z;
		}
		if (x < 0) {
			printf("...\n...\nCannot calculate more!\n...\n...\n");
			return 0;
		}

		else
			printf("%dth num is: %lld\n", m, x);
	}

	return 0;
}

