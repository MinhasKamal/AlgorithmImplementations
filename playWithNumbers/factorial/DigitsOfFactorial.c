/**
*Name: Minhas Kamal (BSSE-0509, IIT, DU)
*Date: 15.May.13
**/

#include <stdio.h>

int main()
{
    for(; ; )
    {
        int a[785], x, i;
        for(i=0; i<785; i++) a[i]=-1;
        scanf("%d", &x);
        if(x<1 || x>366) break;

        int j;
        i=x;
        for(j=784; i>0; j--)
        {
            a[j]=i%10;
            i=i/10;
        }

        int k=0;
        for(i=x-1; i>0; i--)
        {
            for(j=784; a[j]>=0; j--)
            {
                k=(i*a[j])+k;
                a[j]=k%10;
                k=k/10;
            }
            a[j]=k%10;
            k=k/10;
            a[j-1]=k;

            for(k=0; a[k]<1; k++) a[k]=-1;
            k=0;
        }

        int num[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for(i=0; i<10; i++)
            for(j=0; j<785; j++)
                if(i==a[j]) num[i]++;

        printf("%d! --\n", x);
        printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n", num[0], num[1], num[2], num[3], num[4]);
        printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d \n", num[5], num[6], num[7], num[8], num[9]);
    }

    return 0;
}
