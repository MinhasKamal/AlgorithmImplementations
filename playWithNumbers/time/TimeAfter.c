/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: Sep-2013
**/

#include <stdio.h>

int main ()
{
    int s, m, h, p;
    printf("Enter current time (hh. mm. ss): ");
    scanf("%d %d %d", &h, &m, &s);
    printf("Is it 1='am' or 2='pm'? ");
    scanf("%d", &p);

    int as, am, ah;
    printf("Enter addition (hh. mm. ss): ");
    scanf("%d %d %d", &ah, &am, &as);

    int a, x=0;
    if(s+as >= 60){a=s+as-60;  x=1;}
    else a=s+as;

    int b, y=0;
    if(m+am+x >= 60){b=m+am-60+x;  y=1;}
    else b=m+am+x;

    int c = (h+ah+y)%12 + 1;


    printf("\nThe time will be: %d. %d. %d", c, b, a);

    if((h+ah+y)%24 < 12){
    	if(p==1) p=2;
    	else p=1;
    }

    if(p==1)printf(" am\n\n");
    else printf(" pm\n\n");

    return 0;
}

