/**
*Name: Minhas Kamal (IIT, DU)
*Date:24.Feb.2013
**/

#include <stdio.h>

int main() {
	int a;

	printf("Enter number: ");
	scanf("%d", &a);

	long long int n, x = 0, y = 1, z, sum = 0;

	for (n = 1; n < a; n++) {
		sum = sum + y;
		z = y;
		y = x + y;
		x = z;
		if (sum < y) {
			printf("...\n...\nCannot calculate more than %lld!\n...\n...\n", n);
			return 0;
		}
	}
	printf("Sum is: %lld\n\n", sum);

	return 0;
}
