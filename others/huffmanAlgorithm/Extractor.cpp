/**
Name: Minhas Kamal (BSSE-0509, IIT, DU)
Description: This program reads a zip file which ends with '#' & extracts the file.
Date: 21-Oct-2013
**/

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

ifstream input; //file reader
struct node{
    int value;  //value of the node
    char info; //character that it contains
    bool bit;
    node *r,   //root
         *t1,  //left sub tree
         *t2;  //right sub tree
};


void treeBuilder(int* num, node* tree, int x, int S, int E);  //creates the linked tree
void fileExtractor(node* tree, int x);  //writes the extracted file

int main(){
    input.open("huffmanAlgorithm_Input_Zip.txt");   //opening the file

    if(!input.is_open()){   //when the file name is wrong
        printf("Sorry the file is not found!");
        input.close();
        return 0;
    }

    int S,  //the starting char in the ascii table
        E;  //the ending char in the ascii table

    input >> S >> E ;
    //cout << S << " " << E <<endl;   ///test

    int num[E-S];   //holds the number of characters
    for(int i=0; i<E-S; i++){    //taking the input of number of characters
        input >> num[i];
        //cout << num [i] << " "; ///test
    }
    //cout << endl; ///test

    int x=(E-S)*2-1;
    node tree[x];

    treeBuilder(num, tree, x, S, E);

    fileExtractor(tree, x);

    input.close();

    cout << "File Extracted.\n\n";

    return 0;
}


void treeBuilder(int* num, node* tree, int x, int S, int E){
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


void fileExtractor(node* tree, int x){
    FILE *output;
    output=fopen("huffmanAlgorithm_Input_Ext.txt", "w");

    char ch;
    input >> ch;
    while(ch!='#'){ //reading the file & counting the characters
        node* nod;  //for temporary use
        nod=&tree[x-1]; //the main root of tree

        while(nod->t1!=NULL){
            //cout << ch;   ///test

            if(ch=='0') nod = nod->t1;
            else nod = nod->t2;

            input >> ch;
        }
        fprintf(output, "%c", nod->info);
        //cout << nod->info << endl;  ///test
    }

    fprintf(output, "#");   //indicates the end of file

    fclose(output);

    return ;
}


