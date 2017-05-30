/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: Aug-2013
**/

#include <stdio.h>
#include <time.h>

int main()
{
    printf("*#This is a stopwatch#*\n\n\n");
    printf("**Press 'p' to pause.\n");
    printf("**Press any key to start & to stop.");
    getch();
    system("cls");
    printf("\t\t*#This is a stopwatch#*\n\n\n");

    clock_t s, n;
    s = clock();

    while(1){
        while(1){
            n=clock();
            printf("\r");
            printf("Time-\t %d : %d : %d ", ((n-s)/1000)/60, ((n-s)/1000)%60, (n-s)%1000);
            if(kbhit()) break;  //kbhit() does not read the character
        }

        if(getch()=='p'){
            printf("\rTime-\t %d : %d : %d ", ((n-s)/1000)/60, ((n-s)/1000)%60, (n-s)%1000);
            getch();
        }
        else break;

        s=s+(clock()-n);    //split time
        //s=clock();    //lap time
    }

    printf("\rTime-\t %d : %d : %d ", ((n-s)/1000)/60, ((n-s)/1000)%60, (n-s)%1000);

    getch(); getch();  //to read the extra characters
    printf("\n\n\n");

    return 0;
}
