/**
* Name: Minhas Kamal
* Date: 23-Mar-2014
**/

#include <iostream>
#include <stdio.h>

using namespace std;


void LCSFinder(char *firstString, char *secondString);
int stringLength(char *string);
void printLcs(char **direction, char *firstString, int i, int j);


int main(){
    int length = 100;
    char firstString[length],
        secondString[length];

    cout << "Enter two strings: ";
    cin >> firstString >> secondString;

    cout << "Longest common sub-sequence is: ";
    LCSFinder(firstString, secondString);
    cout << "\n";


    return 0;
}


void LCSFinder(char *firstString, char *secondString){
    int firstStringLength = stringLength(firstString),
        secondStringLength = stringLength(secondString);
    //cout << firstStringLength << " " << secondStringLength;

    int index[firstStringLength+1][secondStringLength+1];

    char **direction;
    direction = new char* [firstStringLength];
    for(int i=0; i<firstStringLength; i++)
        direction[i] = new char [secondStringLength];

    for(int i=0; i<firstStringLength+1; i++){
        index[i][0]=0;
    }
    for(int i=0; i<secondStringLength+1; i++){
        index[0][i]=0;
    }

    for(int i=1; i<=firstStringLength; i++){
        for(int j=1; j<=secondStringLength; j++){
            if(firstString[i-1]==secondString[j-1]){
                index[i][j]=index[i-1][j-1]+1;
                direction[i-1][j-1]='\\';       //cross
            }
            else if(index[i-1][j]>=index[i][j-1]){
                index[i][j]=index[i-1][j];
                direction[i-1][j-1]='|';        //up
            }
            else{
                index[i][j]=index[i][j-1];
                direction[i-1][j-1]='-';        //side
            }
        }
    }

    cout << "\nMatrix: \n";
    for(int i=0; i<firstStringLength; i++){     ///test
        for(int j=0; j<secondStringLength; j++){
            cout << index[i+1][j+1] << direction[i][j] << " ";
        }
        cout << "\n";
    }

    //print
    printLcs(direction, firstString, firstStringLength, secondStringLength);

    return;
}


int stringLength(char *string){
    int length=0;
    for(; string[length]!='\0'; length++);

    return length;
}


void printLcs(char **direction, char *firstString, int i, int j){
    if(i==0 || j==0){
        return;
    }

    if(direction[i-1][j-1]=='\\'){      //cross
        printLcs(direction, firstString, i-1, j-1);
        printf("%c", firstString[i-1]);
    }
    else if(direction[i-1][j-1]=='|'){  //up
        printLcs(direction, firstString, i-1, j);
    }
    else if(direction[i-1][j-1]=='-'){  //side
        printLcs(direction, firstString, i, j-1);
    }

    return ;
}

