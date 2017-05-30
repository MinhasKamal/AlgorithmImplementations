/**
* Name: Minhas Kamal (DU,IIT)
* Date: 09.Apr.13
**/

#include <stdio.h>

long int num (int x, int y);
unsigned long long int factorial (int z);

int main ()
{
    int l;

    printf("Enter number of lines: ");
    scanf("%d", &l);
    if(l<1) {printf("Wrong input!"); return 0;}

    printf("\n\n\n\n");

    int a, b, c;

    for(a=0; a<l; a++)
    {
        for(b=9-a; b>0; b--)printf("    ");
        for(c=0; c<=a; c++)
        {
            long int r = num (a, c);
            //printf("%d ", r);

            if(r<1) {printf("\n\n**** Memory Error! ****\n\n"); return 0;}
            else if(r<10) printf("    %d   ", r);
            else if(r<100) printf("   %d   ", r);
            else if(r<1000) printf("   %d  ", r);
            else if(r<10000) printf("  %d  ", r);
            else if(r<100000) printf("  %d ", r);
            else if(r<1000000) printf(" %d ", r);
            else if(r<10000000) printf(" %d", r);
            else if(r>=10000000) printf("%d", r);

        }
        printf("\n\n\n");
    }
    printf("\n\n\n\n");

    return 0;
}

long int num (int x, int y)
{
    unsigned long long int m = factorial(x);
    unsigned long long int n = factorial(y);
    unsigned long long int o = factorial(x-y);

    long int p = m/(n*o);

    return (p);
}

unsigned long long int factorial (int z)
{
    int a;
    unsigned long long int b=1;
    for(a=1; a<=z; a++) b=b*a;

    return (b);
}

