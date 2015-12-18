/**
* Name: Minhas Kamal (BSSE0509, IIT, DU)
* Date: 26-Mar-2013
**/

#include <stdio.h>

void strlen(int s1);
void strcat(int s1, int s2);
void strcmp(int s1, int s2);

char s[20][201];

int main()
{

    int x=20;
    //scanf("%d", &x);
    //printf("Enter the number of strings: ");

    //char s[x][201];

    int y;
    for(y=1; y<=x; y++)
    {
     printf("Enter string No-%d (not more than 200 chars): ", y);
     gets(s[y]);
    }

    for( ; ; )
    {
        int c;
        printf("Enter your choice:\npress\t1 to know the length of string\n\t\t");
        printf("2 to add two strings\n\t\t3 to compare two strings\n\t\t");
        printf("4 to quit.\n\t\t");
        scanf("%d", &c);

        if(c==1)
        {
            int s1;
            printf("Enter string number: ");
            scanf("%d", &s1);
            strlen(s1);
        }
        else if(c==2)
        {
            int s1;
            printf("Enter first string number: ");
            scanf("%d", &s1);
            int s2;
            printf("Enter second string number: ");
            scanf("%d", &s2);
            strcat(s1, s2);
        }
        else if(c==3)
        {
            int s1;
            printf("Enter first string number: ");
            scanf("%d", &s1);
            int s2;
            printf("Enter second string number: ");
            scanf("%d", &s2);
            strcmp(s1, s2);
        }
        else if(c==4) break;
        else if(c<1 || c>4) {printf("Wrong input!"); continue ;}


    }

    return 0;
}


void strlen(int s1)
{
    int c1;
    for(c1=0; s[s1][c1]!='0'; c1++);

    printf("Number of chars: %d", c1);

    return ;
}


void strcat(int s1, int s2)
{
   int c1=0;
    char ns[402];

    int y=0;
    for( ; s[s1][c1]!='0'; )
    {
        ns[y] = s[s1][c1];
        c1++;
        y++;
    }

    int z=y, x=0;
    for( ; s[s2][x]; )
    {
        ns[z] = s[s2][x];
        x++;
        z++;
    }
    ns[z]=0;

    int v=0;
    for( ; ns[v]; v++)printf("%c", ns[v]);

    return ;
}


void strcmp(int s1, int s2)
{
    int f=1, c1=0, c2=0;
    for( ; s[s1][c1]!=0 && s[s2][c2]!=0; )
    {
        if(s[s1][c1] != s[s2][c2]) f=0;

        c1++;
        c2++;
    }
    if(s[s1][c1]==0 && s[s2][c2]!=0) f=-1;
    else if(s[s2][c2]==0 && s[s1][c1]!=0) f=2;

    if(f==1) printf("String matched.");
    else if(f==2) printf("The first one is bigger.");
    else if(f==-1) printf("The second one is bigger.");
    else if(f==0) printf("Size is same but doesn't match.");

    return ;
}
