/**
* Name: Minhas Kamal
* Occupation: Student (DU,IIT)
* Date: 16.May.13
**/

#include <stdio.h>
#include <math.h>
#include <time.h>

int main ()
{
    clock_t start, finish;

    unsigned long long int s, f;   //starting & finishing number

    printf ("Enter your starting number: ");
    scanf ("%lld", &s);

    printf ("Enter your finishing number: ");
    scanf ("%lld", &f);

    start = clock();

    if (s>f) printf("Wrong information!\a\nstarting number is bigger.\a\n");   //starting number should be smaller than finishing number
    else if (s<1 || f<2) printf ("\aError!\a");   //I have done this to save more time

    else
    {
        if(s%2==0) s=(s+1);   //I have made starting number odd, this will save time

        unsigned long long int x;  //holds & increases starting num's value
        long long int y, y2;  //y is the factorial of x & y2 contains square root of x
        char a=0;  //to arrange lines
        char z;   //here z is the flag

        printf("\nThe first prime is: 2\nYour requirements are given bellow:\n\n");

        for(x=s; x<=f; x=x+2)   //the program will work only with odd numbers
        {
            y2=sqrt(x);
            z=1;

            for (y=3; y<=y2; y=y+2)  //verification loop
            {
                if(x%y==0)
                {
                    z=0;
                    break;
                }
            }

            if (z==1)  //printing
            {
                printf("%lld,\t",x);
                a++;

                if(a%10==0)
                {
                    printf("\n");
                    a=0;
                }
            }
        }
        printf("\n\n");
    }

    finish = clock();
    printf("TIME: %d.%.3d sec \n\n", (finish-start)/1000, (finish-start)%1000);

    return 0;
}


