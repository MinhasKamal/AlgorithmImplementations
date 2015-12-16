/**
*Name: Minhas Kamal
*Program Name: StackImplementation
*Date: 04.May.2013
**/

#include <stdio.h>

void stack_size(void);  //working functions
void stack_pop(void);
void stack_push(void);


char c[5]="*****";   //array

int main()
{
    for( ; ; )
    {
        int dis;  //decision input
        printf("Enter your selection: \npress\n\t1.stack size\n\t2.stack pop\n\t3.stack push\n\t4.quit\n");  //selection
        scanf("%d", &dis);
        fflush(stdin);

        if(dis==1) stack_size();  //working according to selection & calling function
        else if(dis==2) stack_pop();
        else if(dis==3) stack_push();
        else break;  //quit
    }
    return 0;
}

void stack_size(void)  //shows size
{
    int i;
    for(i=4; i>=0; i--) if(c[i]!='*') break;
    printf("\nThe size is: %d\n\n\n", i+1);
}

void stack_pop(void)  //printing char
{
    int i;
    for(i=4; i>=0; i--) if(c[i]!='*') break;
    if(i>=0)
    {
        printf("\nIt is: %c\n\n\n", c[i]);
        c[i]='*';
    }
    else printf("\nStack is empty!\n\n\n");
}

void stack_push(void)  //assigns char
{
    int i;
    if(c[4]!='*')
    {
        printf("\nStack is Full.\n\n\n");
        return ;
    }
    for(i=4; i>=0; i--) if(c[i]!='*') break;

    fflush(stdin);
    char ch;
    printf("Enter your input: ");
    scanf("%c", &ch);

    c[i+1]=ch;
}

