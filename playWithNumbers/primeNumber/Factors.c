/**
* Name: Minhas Kamal
* Occupation: Student (DU,IIT)
* Date: 13.May.13
**/

#include <stdio.h>

int main ()
{
    for( ; ; )
    {
        long long int x;
        printf ("Enter your number: ");
        scanf ("%lld", &x);

        if(x<=0)
        {
            printf("\aError!\a\a");
            return 0;
        }
        printf("\n\n");

        long long int y;
        int  z=1;

        for (y=2; y<=x/2; y++)
        {
            if (x%y==0) { printf ("%lld,  ", y); z=0;}
        }

        if(z==1) printf("\aThis is a prime number.\a");

        printf("\n\n");

        int d=1;
        printf("Do you want to continue? 1(y) 0(n).");
        scanf(" %d", &d);
        if(!d) break;
    }

    return 0;
}
