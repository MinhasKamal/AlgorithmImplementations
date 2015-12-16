/********************************
* Developer: Minhas Kamal(BSSE0509)
* Date: Mar-2014
********************************/

#include <stdio.h>
#include <math.h>


#define f(x) sin(x)


int main(){
    int n=100;
    double a=0.0, b=M_PI;
    double h=(b-a)/n;

    double I=0;
    int i;

    I = I + 0.5*f(a);
    for(i=1; i<n-1; i++){
        I = I + f(a+i*h);
    }
    I = I + 0.5*f(b);

    I=I*h;

    printf("Integration is: %lf \n", I);

    return 0;
}
