/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 18-Aug-2013
**/

// Age Calculator

#include <stdio.h>

int main ()
{
    int bd, bm, by;
    printf("Enter your birth day (dd. mm. yy): ");
    scanf("%d %d %d", &bd, &bm, &by);

    int td, tm, ty;
    printf("\nEnter today's date (dd. mm. yy): ");
    scanf("%d %d %d", &td, &tm, &ty);

    int d, a=0;
    if(td<bd){d=30+td-bd+1;  a=-1;}
    else d=td-bd+1;

    int m, b=0;
    if(tm<bm){m=12+tm-bm+a;  b=-1;}
    else m=tm-bm+a;

    int y=ty-by+b;


    printf("\nYour age is (yy, mm, dd): %d. %d. %d\n", y, m, d);
    getch();
    return 0;
}
