/**
* Name: Minhas Kamal (DU,IIT)
* Date: 09.Apr.13
**/

#include <stdio.h>

int main()
{
    int l;
    printf("Enter number of lines: ");
    scanf("%d", &l);

    int z, *p[100];
    *p=0;
    *(p+1)=1;
    *(p+2)=0;

    for(z=1; z<=l; z++)
    {
        int i, j, t;

        for(i=0; i<z+1; i++)
        {
            if(*(p+i)) printf("%d", *(p+i));
        }

        for(j=1; j<=z; j++)
        {
            //t = *(p+j);
            //*(p+j) = *p + *(p+j);
            t = *p[j];
            *p[j] = *p[j-1] + *p[j];
            *p[j+2] = *p[j+1];
            *p[j+1] = t;
            //*(p+j+2) = *(p+j+1);
            //*(p+j+1) = t;
        }
    }
    return 0;
}
