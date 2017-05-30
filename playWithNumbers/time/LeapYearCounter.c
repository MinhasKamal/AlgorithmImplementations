/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 25-May-2013
**/

#include <stdio.h>

int main()
{
    for(; ; )
    {
        int y;
        printf("Enter your year: ");
        scanf("%d", &y);

        if(y%400==0) printf("%d is a leap year.\n", y);
        else if(y%100==0) printf("%d is not a leap year.\n", y);
        else if(y%4==0) printf("%d is a leap year.\n", y);
        else printf("%d is not a leap year.\n", y);

        char ch;
        printf("Press 'c' to continue.\n");
        fflush(stdin);
        scanf("%c", &ch);

        printf("\n");

        if(ch!='c' && ch!='C') break;
    }

    return 0;
}
