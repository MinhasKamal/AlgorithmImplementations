/**
* Name: Minhas Kamal (DU,IIT)
* Date: 08.Apr.13
**/

#include <stdio.h>

int num (int x, int y);
long long int factorial (int z);

int main ()
{
    int l;

    printf("Enter number of lines: ");
    scanf("%d", &l);
    printf("\n\n\n\n");

    int a, b, c;

    for(a=0; a<l; a++){
        for(b=39-a; b>0; b--)printf(" ");
        for(c=0; c<=a; c++){
                int r = num (a, c);
                printf("%d ", r);
        }
        printf("\n");
    }
    printf("\n\n\n\n");

    return 0;
}

int num (int x, int y)
{
    long long int m = factorial(x);
    long long int n = factorial(y);
    long long int o = factorial(x-y);

    int p = m/(n*o);

    return (p);
}

long long int factorial (int z)
{
    int a;
    long long int b=1;
    for(a=1; a<=z; a++) b=b*a;

    return (b);
}
