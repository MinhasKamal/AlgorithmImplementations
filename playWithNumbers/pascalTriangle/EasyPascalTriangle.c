/**
* Name: Minhas Kamal (DU,IIT)
* Date: 13.Apr.13
**/

#include <stdio.h>

int main()
{
    int a[50][50], x, i,j;

    printf("Enter the number of rows: ");
    scanf("%d", &x);

    for(i=0;i<=x;i++)
    {
        for(j=0;j<i;j++)
        {
            if(j==0 || j==i)
            {
                a[i][j]=1;
            }

            else
            {
                a[i][j]=a[i-1][j]+a[i-1][j-1];
            }
        }
    }

    for(i=0;i<=x;i++)
    {
        for(j=x-i;j>0;j--)
            printf("   ");

        for(j=0;j<i;j++)
            printf("%6d", a[i][j]);

        printf("\n\n");
    }

    return 0;

}
