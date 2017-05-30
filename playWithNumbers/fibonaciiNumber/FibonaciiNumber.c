/**
*Name: Minhas Kamal (IIT, DU)
*Date:24.Feb.2013
**/

#include <stdio.h>

int main() {
	int a;

	printf("Enter number: ");
	scanf("%d", &a);

	long long int n, x = 0, y = 1, z;

	for (n = 1; n < a; n++) {
		z = y;
		y = x + y;
		x = z;
		if (x < 0) {
			printf("...\n...\nCannot calculate more than %lld!\n...\n...\n", n);
			return 0;
		}
	}

	printf("The num is: %lld\n\n", x);

	return 0;
}

