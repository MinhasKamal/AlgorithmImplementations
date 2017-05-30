/**
* Name: Minhas Kamal
* Occupation: Student (DU,IIT)
* Date: Apr.13
**/

#include <stdio.h>

void varify (long int m, long int n);

int main ()
{
    long int s,f;   //starting & finishing number

    printf ("Enter your starting number: ");
    scanf ("%ld", &s);

    printf ("Enter your finishing number: ");
    scanf ("%ld", &f);

    if (s>f) printf("Wrong information!\a\nstarting number is bigger.\a\n");
    else if (s<2 || f<3) printf ("\aError!\a");

    else{
        printf("\nThe first prime is: 2\nYour requirements are given bellow:\n\n");
        varify (s,f);
                        }
        printf("\n\n");

    return 0;
}


void varify (long int m, long int n)  //all works are done here
{
    long int w;
    if(m%2==0) w=(m+1);
    else w=m;

    for(m=w; m<=n; m=m+2){
                        long int y, z=1;
                        for (y=3; y<=m/3; y=y+2){
                                               if(m%y==0) z=0;
                                               }
                        if (z==1)printf("%ld,\t",m);
    }

    return ;
}


