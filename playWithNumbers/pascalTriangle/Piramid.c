/**
* Name: Minhas Kamal (DU,IIT)
* Date: 22.Feb.13
**/

#include <stdio.h>

int main ()
{
    int l;

    printf("Enter number of lines: ");
    scanf("%d", &l);

    int a, b, c;

    for(a=0; a<=l; a++){
        for(b=l-a; b>0; b--)printf(" ");
        for(c=0; c<(2*a)-1; c++)printf("|");
        printf("\n");
    }

    return 0;
}


