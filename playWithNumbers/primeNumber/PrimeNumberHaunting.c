/**
* Name: Minhas Kamal
* Occupation: Student (DU,IIT)
* Date: Apr.13
**/

#include <stdio.h>

int main ()
{
    long int l;
    printf("Enter your limit: ");
    scanf("%ld", &l);

    long int x;
    printf("2,\t");
    for(x=3; x<=l; x=x+2){
        long int y;
        int z=1;

        for (y=3; y<=x/3; y=y+2){
            if(x%y==0)
                z=0;
        }
        if (z==1)
            printf("%ld,\t",x);
    }

    return 0;
}
