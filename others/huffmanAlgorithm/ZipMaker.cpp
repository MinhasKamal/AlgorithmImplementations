/**
Name: Minhas Kamal (BSSE-0509, IIT, DU)
Description: This program reads a text file which ends with '#' & Zips the file.
Date: 21-Oct-2013
**/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

#define S 97    //the starting char in the ascii table
#define E 123   //the ending char in the ascii table


ifstream input; //file reader
struct node{
    int value;  //value of the node
    char info; //character that it contains
    bool bit;
    node *r,   //root
         *t1,  //left sub tree
         *t2;  //right sub tree
};


void charCounter(int* num); //counts characters in a file
void treeBuilder(int* num, node* tree, int x);  //creates the linked tree
void zipFileWriter(int* num, node* tree);


int main(){
    int num[E-S];   //holds the number of characters

    charCounter(num);  //reading a file & counting the number of different characters

    int x=(E-S)*2-1;
    node tree[x];

    treeBuilder(num, tree, x);

    zipFileWriter(num, tree);

    cout << "Zip file is made.\n";

    return 0;
}



void charCounter(int* num){
    input.open("huffmanAlgorithm_Input.txt");   //opening the file

    if(!input.is_open()){   //when the file name is wrong
        printf("Sorry the file is not found!");
        input.close();
        return ;
    }

    for(int i=0; i<E-S; i++)    //initializing
        num[i]=0;

    ///I Want to read the file as string and identify space & newline


    char ch;
    input >> ch;
    while(ch!='#'){ //reading the file & counting the characters
        //cout << ch <<" "; ///test
        if(ch>=S && ch<E) num[ch-S]++;
        input >> ch;
    }

    /*/for(int i=S; i<E; i++){ //the output after the input file's characters are counted
        char c = (char) i;
        cout << i << ". " << c << "  " << num[i-S] << endl;
    }/**/

    input.close();

    return ;
}



void treeBuilder(int* num, node* tree, int x){
    for(int i=0; i<x; i++){ //initialization
        tree[i].value = -1;
        tree[i].info = (char)0;
        tree[i].bit = false;
        tree[i].r = NULL;
        tree[i].t1 = NULL;
        tree[i].t2 = NULL;
    }


    int position=0; //position in the array

    for(; position<E-S; position++){    //setting the value of the initial nodes
        tree[position].value = num[position];
        tree[position].info = (char)(position+S);
    }

    int lt,   //left sub tree
        rt;   //right sub tree
    while(position<x){   //building up the tree
        for(int i=0; i<x; i++) //initialization
            if(tree[i].r==NULL && tree[i].value>=0){
                lt=i;
                break;
            }

        for(int i=0; i<x; i++){ //finds left sub tree (smallest value)
            if(tree[i].r==NULL && tree[i].value>=0)
                if(tree[i].value < tree[lt].value) lt=i;
        }
        tree[lt].r = &tree[position];   //setting the root of the left sub trees


        for(int i=0; i<x; i++) //initialization
            if(tree[i].r==NULL && tree[i].value>=0){
                rt=i;
                break;
            }

        for(int i=0; i<x; i++){ //finds right sub tree (second smallest value)
            if(tree[i].r==NULL && tree[i].value>=0)
                if(tree[i].value < tree[rt].value) rt=i;
        }
        tree[rt].r = &tree[position];   //setting the root of the right sub trees


        tree[lt].bit = false;   //setting the bit of the sub trees
        tree[rt].bit = true;

        tree[position].value = (tree[lt].value + tree[rt].value);   //the value is the sum of the sub trees
        tree[position].t1 = &tree[lt];  //setting sub tree of new node
        tree[position].t2 = &tree[rt];

        position++; //increasing the position
    }


    /*/for(int i=0; i<x; i++){ //test of the node
        cout << tree[i].value << " " << tree[i].info << " " << tree[i].bit << " ";
        cout << tree[i].r << " " << tree[i].t1 << " " << tree[i].t2 << endl;
    }/**/

    return ;
}



void zipFileWriter(int* num, node* tree){
    input.open("huffmanAlgorithm_Input.txt");   //opening the file

    if(!input.is_open()){   //when the file name is wrong
        printf("Sorry the file is not found!");
        input.close();
        return ;
    }

    FILE *output;
    output=fopen("huffmanAlgorithm_Input_Zip.txt", "w");

    fprintf(output, "%d %d \n", S, E);    //printing start & end of characters
    for(int i=0; i<E-S; i++)    //printing number of characters
        fprintf(output, "%d ", num[i]);
    fprintf(output, "\n");

    char ch;
    stack<bool> mystack;
    input >> ch;
    while(ch!='#'){ //reading the file once more & writing in the output file
        //cout << ch <<" "; ///test

        int i;
        for(i=0; i<E-S; i++){   //finding the char in the node
            if(tree[i].info==ch) break;
        }

        node* nod;  //for temporary use
        nod=&tree[i];
        while(nod->r!=NULL){    //assigning bits in the stack
            mystack.push(nod->bit);   //bit of the node
            nod=nod->r; //assigning the root
        }


        while(!mystack.empty()){    //writing in the output file
            //cout << mystack.top();  ///test
            //fputc(mystack.top(), output);
            fprintf(output, "%d", mystack.top());
            mystack.pop();
        }
        //cout << endl; ///test

        input >> ch;    //taking the input
    }
    fprintf(output, "#");   //indicates the end of file

    fclose(output);
    input.close();

    return ;
}



//*/cout << "\nIts all good!!\n";    //debugging unit
