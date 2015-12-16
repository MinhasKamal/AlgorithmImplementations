/********************************
* Developer: Minhas Kamal(BSSE0509)
* Date: Mar-2014
********************************/

#include <stdio.h>
#include <math.h>


int main(){
    int n=201;

    double x[n], fx[n], fx2[n];

    double a=0.0, b=2*M_PI;
    double h=(b-a)/n;


    int i;
    x[0]=a;
    fx[0]=sin(x[0]);                           //calculation of function
    for(i=1; i<n-1; i++){
        x[i] = a + i*h;
        fx[i] = sin(x[i]);
    }
    x[n-1]=b;
    fx[n-1]=sin(x[n-1]);


    fx2[0] = (fx[1]-fx[0]) / (x[1]-x[0]);
    for(i=1; i<n-1; i++){
        fx2[i] = (fx[i+1]-fx[i-1]) / (x[i+1]-x[i-1]);
    }
    fx2[n-1] = (fx[n-1]-fx[n-2]) / (x[n-1]-x[n-2]);


    printf("x \t\tf(x) \t\tf'(x) \n");  //traverse
    for(i=0; i<n; i++){
        printf("%lf \t%lf \t%lf \n", x[i], fx[i], fx2[i]);
    }

    return 0;
}
