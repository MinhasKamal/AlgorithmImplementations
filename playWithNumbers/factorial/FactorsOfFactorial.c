/**
*Name: Minhas Kamal (BSSE-0509, IIT, DU)
*Date: 12.May.13
**/

#include <stdio.h>

void varify(int x);

int n[25];

int main()
{
    for(; ; )
    {
        int p;
        for(p=0; p<25; p++) n[p]=0;

        int i, j;
        scanf("%d", &i);
        if(i==0) break;
        if(i>100 || i<2) continue;


        for(j=2; j<=i; j++) varify(j);

        for(j=24; n[j]==0; j--);

        printf("%3d! =", i);

        for(i=0; i<=j; i++)
        {
            printf("%3d", n[i]);

            if((i+1)%15==0) printf("\n      ");
        }
        printf("\n");
    }


    return 0;
}

void varify(int x)
{
    int d=x;
    while(d%2==0)
    {
        n[0]++;
        d=d/2;
    }

    int a, b, c=1;
    for(a=3; a<=x; a=a+2)
    {
        int z=1;
        for (b=3; b<=a/3; b=b+2)
        {
            if(a%b==0)
            {
                z=0;
                break;
            }
        }
        if(z==1)
        {
            d=x;
            while(d%a==0)
            {
                n[c]++;
                d=d/a;
            }
            c++;
        }
    }
    return ;
}


