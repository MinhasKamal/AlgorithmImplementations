/**
*Name: Minhas Kamal
*Date:04.May.2013
**/

#include <stdio.h>


int main()
{
    long int a, b, a1, b1;
    printf("Enter two positive integers: ");  //asking the user
    scanf("%ld %ld", &a, &b);
    a1=a;  //to store the main value
    b1=b;  //to store the main value

    if(a<1 || b<1)  //input check
    {
        printf("Invalid input!");
        exit(1);
    }

    for( ; ; )  //main operation for first integer
    {
        int af=0;
        for( ; a>10; a=a/10)
        {
            af=af+(a%10);
        }
        af=af+a;
        a=af;
        if(a<10) break;  //breaking the loop
    }

     for( ; ; )  //main operation for second integer
     {
        int bf=0;
        for( ; b>10; b=b/10)
        {
            bf=bf+(b%10);
        }
        bf=bf+b;
        b=bf;
        if(b<10) break;  //breaking the loop
     }

    if(a==b) printf("%ld and %ld are friends\n", a1, b1);  //output
    else printf("%ld and %ld are not friends\n", a1, b1);

    return 0;
}


