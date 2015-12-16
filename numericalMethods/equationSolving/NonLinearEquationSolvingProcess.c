/********************************
* Developer: Minhas Kamal(BSSE0509)
* Date: 05-Feb-2014
********************************/

#include <stdio.h>
#include <math.h>


/// Here define different functions to work with
//1st function set
#define f(x) ( ((x)*(x)*(x)) - (x) - 2 )
#define f2(x) ( (3*(x)*(x)) - 1 )
#define g(x) ( cbrt( (x) + 2 ) )
//2nd function set
//#define f(x) ( ((x)*(x)*(x)) - (4*(x)) - 8.95 )
//#define f2(x) ( (3*(x)*(x)) - 4 )
//#define g(x) ( cbrt( (4*(x)) + 8.95 ) )


//functions using different methods in solving the same problem
double BisectionMethod();
double FalsePosition();
double NewtonRaphson();
double FixedPoint();
double Secant();


int main(){
    double root;

    root = BisectionMethod();
    printf("Using Bisection Method the root is: %lf \n\n", root);
	
    root = FalsePosition();
    printf("Using False Position Method the root is: %lf \n\n", root);
	
    root = NewtonRaphson();
    printf("Using Newton-Raphson Method the root is: %lf \n\n", root);
	
    root = FixedPoint();
    printf("Using Fixed Point Method the root is: %lf \n\n", root);
	
    root = Secant();
    printf("Using Secant Method the root is: %lf \n\n", root);

    return 0;
}

/**
* takes two initial values and shortens the distance by both side
**/
double BisectionMethod(){
    double root=0;

    double a=1, b=2;
    double c=0;

    int loopCounter=0;
    if(f(a)*f(b) < 0){
        while(1){
            loopCounter++;
            c=(a+b)/2;

            if(f(c)<0.00001 && f(c)>-0.00001){
                root=c;
                break;
            }

            if((f(a))*(f(c)) < 0){
                b=c;
            }else{
                a=c;
            }

        }
    }
    printf("It took %d loops.\n", loopCounter);

    return root;
}

/**
* takes two initial values and shortens the distance by single side
**/
double FalsePosition(){
    double root=0;

    double a=1, b=2;
    double c=0;

    int loopCounter=0;
    if(f(a)*f(b) < 0){
        while(1){
            loopCounter++;

            c=(a*f(b) - b*f(a)) / (f(b) - f(a));

            /*/printf("%lf\t %lf \n", c, f(c));/**////test
            if(f(c)<0.00001 && f(c)>-0.00001){
                root=c;
                break;
            }

            if((f(a))*(f(c)) < 0){
                b=c;
            }else{
                a=c;
            }
        }
    }
    printf("It took %d loops.\n", loopCounter);

    return root;
}

/**
* uses one initial value and gradually takes that value near to the real one
**/
double NewtonRaphson(){
    double root=0;

    double x1=1;
    double x2=0;

    int loopCounter=0;
    while(1){
        loopCounter++;

        x2 = x1 - (f(x1)/f2(x1));
        /*/printf("%lf \t %lf \n", x2, f(x2));/**////test

        if(f(x2)<0.00001 && f(x2)>-0.00001){
            root=x2;
            break;
        }

        x1=x2;
    }
    printf("It took %d loops.\n", loopCounter);

    return root;
}

/**
* uses one initial value and gradually takes that value near to the real one
**/
double FixedPoint(){
    double root=0;
    double x=1;

    int loopCounter=0;
    while(1){
        loopCounter++;

        if( (x-g(x)) <0.00001 && (x-g(x)) >-0.00001){
            root = x;
            break;
        }

        /*/printf("%lf \t %lf \n", g(x), x-(g(x)));/**////test

        x=g(x);
    }
    printf("It took %d loops.\n", loopCounter);

    return root;
}

/**
* uses two initial values & both value approaches to the root
**/
double Secant(){
    double root=0;

    double x0=1;
    double x1=2;
    double x2=0;

    int loopCounter=0;
    while(1){
        loopCounter++;

        /*/printf("%lf \t %lf \t %lf \n", x0, x1, f(x1));/**////test

        if(f(x1)<0.00001 && f(x1)>-0.00001){
            root=x1;
            break;
        }

        x2 = ((x0*f(x1))-(x1*f(x0))) / (f(x1)-f(x0));

        x0=x1;
        x1=x2;
    }
    printf("It took %d loops.\n", loopCounter);

    return root;
}

