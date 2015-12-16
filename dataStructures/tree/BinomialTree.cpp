/**
* Programmer: Minhas Kamal (BSSE0509,IIT,DU)
* Date: 30-Mar-2014
**/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define X 3

struct node{
    int value;
    int depth;
    node *previous;
    node *next[X];
} nullNode;



int main(){
    ///input array
    int arrayLength=1;
    for(int i=0; i<X; i++){
        arrayLength = arrayLength * 2;
    }
    int array[arrayLength];
    for(int i=0; i<arrayLength; i++){
        array[i]=rand()%100;
        printf("%d \n", array[i]);///test
    }

    ///initialize null node
    nullNode.value=-1;
    nullNode.depth=0;
    nullNode.previous=NULL;
    for(int i=0; i<X; i++){
        nullNode.next[i]=NULL;
    }

    ///constructing binomial tree
    bool similarityFound=true;
    node binomialTree[arrayLength];
    for(int i=0; i<arrayLength; i++){
        ///initialization
        binomialTree[i].value = array[i];
        binomialTree[i].depth = 0;
        binomialTree[i].previous = &nullNode;
        for(int j=0; j<X; j++){
            binomialTree[i].next[j] =NULL;
        }
        nullNode.next[nullNode.depth]=&binomialTree[i];
        nullNode.depth++;

        ///finding & merging similar trees
        int newNode=i;
        while(1){
            similarityFound=false;
            int j;
            for(j=0; j<nullNode.depth-1; j++){
                if(nullNode.next[j]->depth==binomialTree[newNode].depth)
                    similarityFound=true;
            }

            if(similarityFound){
                if(binomialTree[j].value < binomialTree[newNode].value){
                    binomialTree[j].next[binomialTree[j].depth]=&binomialTree[newNode];
                    binomialTree[newNode].previous=&binomialTree[j];
                    newNode=j;
                    binomialTree[j].depth++;
                }
                else{
                    binomialTree[newNode].next[binomialTree[newNode].depth]=&binomialTree[j];
                    binomialTree[j].previous=&binomialTree[newNode];
                    newNode=newNode;
                    binomialTree[newNode].depth++;
                }

                nullNode.depth--;
                nullNode.next[nullNode.depth]=&binomialTree[newNode];

            }else{
                break;
            }

        }
    }

    ///traversing
    for(int i=0; i<arrayLength; i++){
        cout << &binomialTree[i] << "\t" << binomialTree[i].value << "\t";
        cout << binomialTree[i].depth << "\t" << binomialTree[i].previous << "\t";
        for(int j=0; j<X; j++){
            cout << binomialTree[i].next[j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
