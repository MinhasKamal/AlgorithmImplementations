/********************************
* Developer: Minhas Kamal(BSSE0509)
* Date: Mar-2014
********************************/

#include <stdio.h>
#include <math.h>


#define f1(x) ((x)-5) * ((x)-5)
#define f2(x) 0
#define f(x) (f1(x))-(f2(x))

int main(){
    int n=100;
    double a=-5, b=5;
    double h=(b-a)/n;

    double I=0;
    int i;

    I = I + 0.5*f(a);
    for(i=1; i<n-1; i++){
        I = I + f(a+i*h);
    }
    I = I + 0.5*f(b);

    I=I*h;

    printf("Area is: %lf \n", I);

    return 0;
}
