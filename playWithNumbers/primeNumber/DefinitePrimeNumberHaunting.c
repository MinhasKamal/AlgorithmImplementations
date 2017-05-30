/**
*Name: Minhas Kamal
*Occupation: Student (DU,IIT)
*Date: 16.May.13
**/

#include <stdio.h>
#include <math.h>
#include <time.h>

int main ()
{
    clock_t start, finish;

    long long int a, b;  //domain
    printf("Enter your starting number: ");
    scanf("%lld", &a);
    printf("Enter your finishing number: ");
    scanf("%lld", &b);

    int k, s;
    printf("Enter your number of primes: ");
    scanf("%d", &k);
    printf("Enter the distance: ");
    scanf("%d", &s);
    printf("\n");

    if(a>b) exit(1);
    long long int tup[k];

    start = clock();

    int i;
    for(i=0; i<k-1; i++) tup[i]=-100;
    tup[k-1]=2;

    if(a%2==0) a=(a+1);  //odd making

    long long int x;
    long long int y, x2;
    char fl;
    int ans=0;

    for(x=a; x<=b; x=x+2)   //the program will work only with odd numbers
    {
        x2=sqrt(x);
        fl=1;

        for (y=3; y<=x2; y=y+2)  //verification loop
            if(x%y==0)
            {
                fl=0;
                break;
            }

        if (fl==1)  //printing
        {
            for(i=0; i<(k-1); i++) tup[i]=tup[i+1];
            tup[k-1]=x;

            if((tup[k-1]-tup[0])==s)
            {
                int j;
                for(j=0; j<k; j++) printf("%7d", tup[j]);
                printf("\n");
                ans++;
            }
        }
    }

    printf("\nNumber of tuples: %d\n", ans);

    finish = clock();
    printf("Time: %d.%.3d sec \n\n", (finish-start)/1000, (finish-start)%1000);


    return 0;
}



