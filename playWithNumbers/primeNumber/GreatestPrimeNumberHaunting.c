/**
* Name: Minhas Kamal
* Occupation: Student (DU,IIT)
* Date: May.13
* Comment: I have tried to make this program more time efficient, but at the same
* time more complex. It finds all prime number in its domain (3 - 18,446,744,073,709,551,616).
**/

#include <stdio.h>
#include <math.h>
#include <time.h>

int main ()
{
    clock_t st, fn;

    long long int s,f;   //starting & finishing number

    printf ("Enter your starting number: ");
    scanf ("%lld", &s);

    printf ("Enter your finishing number: ");
    scanf ("%lld", &f);

    st=clock();

    if (s>f)
    {   //Starting number is smaller than finishing number
        long long int temp = s;
        s=f;
        f=temp;
    }

    if (s<2)
    {
        s=2;
    }

    if(f<3)
    {
        f=3;
    }

    else
    {
        printf("\n\n##Prime numbers are:\n\n");
        if(s<3){
            printf("2,\t");
        }

        long long int x, w;

        if(s%2==0) w=(s+1);   //I have made starting number odd, this will save time
        else w=s;

        for(x=w; x<=f; x=x+2)   //The program will work only with odd numbers
        {
            int z=1;  //Here z is the flag
            long long int y;

            if(x>500)
            {
                if(x%3 == 0) z=0;
                else if(x%5 == 0) z=0;
                else if(x%7 == 0) z=0;
                else if(x%11 == 0) z=0;
                else if(x%13 == 0) z=0;
                else if(x%17 == 0) z=0;
                else if(x%19 == 0) z=0;
                else if(x%23 == 0) z=0;
                else if(x%29 == 0) z=0;
                else if(x%31 == 0) z=0;
                else if(x%37 == 0) z=0;
                else if(x%41 == 0) z=0;
                else if(x%43 == 0) z=0;
                else if(x%47 == 0) z=0;

                else if(x%53 == 0) z=0;
                else if(x%59 == 0) z=0;
                else if(x%61 == 0) z=0;
                else if(x%67 == 0) z=0;
                else if(x%71 == 0) z=0;
                else if(x%73 == 0) z=0;
                else if(x%79 == 0) z=0;
                else if(x%83 == 0) z=0;
                else if(x%89 == 0) z=0;
                else if(x%97 == 0) z=0;

                else if(x%101 == 0) z=0;
                else if(x%103 == 0) z=0;
                else if(x%107 == 0) z=0;
                else if(x%109 == 0) z=0;
                else if(x%113 == 0) z=0;
                else if(x%127 == 0) z=0;
                else if(x%131 == 0) z=0;
                else if(x%137 == 0) z=0;
                else if(x%139 == 0) z=0;
                else if(x%149 == 0) z=0;

                else if(x%151 == 0) z=0;
                else if(x%157 == 0) z=0;
                else if(x%163 == 0) z=0;
                else if(x%167 == 0) z=0;
                else if(x%173 == 0) z=0;
                else if(x%179 == 0) z=0;
                else if(x%181 == 0) z=0;
                else if(x%191 == 0) z=0;
                else if(x%193 == 0) z=0;
                else if(x%197 == 0) z=0;
                else if(x%199 == 0) z=0;

                else if(x%211 == 0) z=0;
                else if(x%223 == 0) z=0;
                else if(x%227 == 0) z=0;
                else if(x%229 == 0) z=0;
                else if(x%233 == 0) z=0;
                else if(x%239 == 0) z=0;
                else if(x%241 == 0) z=0;

                else if(x%251 == 0) z=0;
                else if(x%257 == 0) z=0;

                else for (y=263; y<=sqrt(x); y=y+2)
                     {
                         if(x%y == 0) {z=0; break;}
                     }
            }

        else for(y=3; y<=x/3; y=y+2) {if(x%y == 0) z=0;}


        if(x<s || x<0){printf ("\n\aUnable to do more!\a\n\n");  return 0;}

        else if (z==1) printf("%lld,\t",x);
        }
        printf("\n\n**END**\n");
    }

    fn=clock();

    printf("\n\n**TIME: %d.%d sec \n\n", (fn-st)/1000, (fn-st)%1000);

    //pause
    char c;
    scanf("%c%c", &c, &c);

    return 0;
}


