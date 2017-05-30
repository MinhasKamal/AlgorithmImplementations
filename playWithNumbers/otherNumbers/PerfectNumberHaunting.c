/**
*Name: Minhas Kamal
*Date:02.Jan.2014
**/

#include <stdio.h>

int main()
{
    long long int s;
    printf("Enter the starting number: ");
    scanf("%lld", &s);

    long long int f;
    printf("Enter the finishing number: ");
    scanf("%lld", &f);

    long long int a, b;

    for(a=s ; a<=f; a++)
    {
        if(a%2!=0) continue;

        long long int c=0;
        for(b=1; b<=(a/3); b++)
        {
            if(a%b==0) c=c+b;
        }
        if(a/2==c) printf("%lld, ", a);
    }

    getchar(); getchar();

    return 0;
}
