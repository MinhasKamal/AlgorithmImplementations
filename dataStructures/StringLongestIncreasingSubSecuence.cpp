/**
* Programmer: Minhas Kamal (BSSE0509,IIT,DU)
* Date: 24-Apr-2014
**/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

#define X 30

int main(){
    int array[X+1];
    array[0]=0;
    for(int i=1; i<X+1; i++){
        array[i] = rand()%100;
        cout << array[i] << endl;   ///test
    }


    ///define relation
    int prevIndex[X+1];
    int position[X+1];

    prevIndex[0]=0;
    position[0]=0;
    for(int i=1; i<X+1; i++){
        prevIndex[i]=0;
        position[i]=0;

        for(int j=1; j<i; j++){
            if(array[i]>=array[j]){
                if(position[j]>position[i]){
                    position[i]=position[j];
                    prevIndex[i]=j;
                }
            }
        }
        position[i]++;
    }

    ///traverse             ///test
    /*for(int i=0; i<X+1; i++){
        cout << array[i] << " " << prevIndex[i] << " " << position[i] << endl;
    }*/

    ///finding the largest sequence's last element
    int length=0;
    int index=0;
    for(int i=0; i<X+1; i++){
        if(position[i]>length){
            length=position[i];
            index=i;
        }
    }

    ///sub sequence
    stack<int> subSequence;
    while(prevIndex[index]!=0){
        subSequence.push(array[index]);
        index = prevIndex[index];
    }
    subSequence.push(array[index]);

    while(!subSequence.empty()){
        cout << subSequence.top() << endl;
        subSequence.pop();
    }

    return 0;
}
