/**
* Programmer: Minhas Kamal (BSSE0509,IIT,DU)
* Date: 18-Apr-2014
**/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node{
    int value;
    node *next[2];
    node *previous;
};

int main(){
    ///any integerarray
    int length=18;
    int array[]={12,23,34,4,5,6,676,78,8,34,32,3,5,657,6,54,4,4};

    ///main node
    node elements[100];
    for(int i=0; i<100; i++){
        elements[i].value=-4200;

        elements[i].next[0]=NULL;
        elements[i].next[1]=NULL;
        elements[i].previous=NULL;
    }

    elements[0].value=array[0];
    elements[0].next[0]=&elements[1];
    elements[0].next[1]=&elements[2];
    elements[0].previous=NULL;

    ///constructs the binary heap
    for(int i=1; i<length; i++){
        elements[i].value=array[i];

        elements[i].next[0]=&elements[2*i+1];
        elements[i].next[1]=&elements[2*i+2];
        elements[i].previous=&elements[(int)((i-1)/2)];

        int position=i;
        while(elements[position].previous!=NULL){
            if(elements[position].value < elements[position].previous->value){
                int temp=elements[position].value;
                elements[position].value=elements[position].previous->value;
                elements[position].previous->value=temp;


                position=(int) (position-1)/2;
            }
            else{
                break;
            }
        }
    }


    ///traverse
    cout << "After making binary heap-> ";
    for(int i=0; i<length; i++){
        printf("%d, ", elements[i].value);
    }
    cout << "\n\n";

    ///perform operation
    int currentPosition=length;
    int selection=1;
    while(selection){
        cout << "\nWhat type of operation you want to perform? \n##Press: \n\t1.find minimum";
        cout << "\n\t2.delete minimum \n\t3.insert new \n\t4.delete \n\t5.edit";
        cout << "\n\t6.traverse \n\t7.exit \n\nSelection: ";
        cin >> selection;

        if(selection==1){           //find minimum
            cout << "Minimum element is: " << elements[0].value;
        }
        else if(selection==2){     //delete minimum
            int value=elements[0].value;
            elements[0].value=elements[currentPosition-1].value;
            elements[currentPosition-1].value=value;

            currentPosition--;

            int position=0;
            while(2*position < currentPosition){
                if(elements[position].value > elements[position].next[1]->value &&
                        elements[position].next[1]->value <= elements[position].next[0]->value){
                    int temp=elements[position].value;
                    elements[position].value=elements[position].next[1]->value;
                    elements[position].next[1]->value=temp;

                    position=2*position+2;
                }else if(elements[position].value > elements[position].next[0]->value){
                    int temp=elements[position].value;
                    elements[position].value=elements[position].next[0]->value;
                    elements[position].next[0]->value=temp;

                    position=2*position+1;
                }else{
                    break;
                }
            }

            cout << "Minimum is Deleted!";
        }
        else if(selection==3){     //insert new
            int value;
            cout << "\nEnter the value: ";
            cin >> value;

            elements[currentPosition].value=value;

            elements[currentPosition].next[0]=&elements[2*currentPosition+1];
            elements[currentPosition].next[1]=&elements[2*currentPosition+2];
            elements[currentPosition].previous=&elements[(int)((currentPosition-1)/2)];


            int position=currentPosition;
            while(elements[position].previous!=NULL){
                if(elements[position].value < elements[position].previous->value){
                    int temp=elements[position].value;
                    elements[position].value=elements[position].previous->value;
                    elements[position].previous->value=temp;


                    position=(int) (position-1)/2;
                }else{
                    break;
                }
            }


            currentPosition++;
            cout << "Inserted!";
        }
        else if(selection==4){     //delete
            int value;
            cout << "\nEnter the value of the element: ";
            cin >> value;

            int position=-1;
            for(int i=0; i<currentPosition; i++){
                if(elements[i].value==value) {
                    position=i;
                    //printf("%d, ", elements[i].value);
                    break;
                }
            }


            if(position==-1){
                cout << "Value is not found!";
            }else{
                int value=elements[position].value;
                elements[position].value=elements[currentPosition-1].value;
                elements[currentPosition-1].value=value;

                currentPosition--;

                while(2*position < currentPosition){
                    if(elements[position].value > elements[position].next[1]->value &&
                            elements[position].next[1]->value <= elements[position].next[0]->value){
                        int temp=elements[position].value;
                        elements[position].value=elements[position].next[1]->value;
                        elements[position].next[1]->value=temp;

                        position=2*position+2;
                    }else if(elements[position].value > elements[position].next[0]->value){
                        int temp=elements[position].value;
                        elements[position].value=elements[position].next[0]->value;
                        elements[position].next[0]->value=temp;

                        position=2*position+1;
                    }else{
                        break;
                    }
                }
                cout << "Deleted!";
            }
        }
        else if(selection==5){     //edit
            int value;
            cout << "\nEnter the value of the element: ";
            cin >> value;

            int position=-1;
            for(int i=0; i<currentPosition; i++){
                if(elements[i].value==value) {
                    position=i;
                    //printf("%d, ", elements[i].value);
                    break;
                }
            }


            if(position==-1){
                cout << "Value is not found!";
            }else{
                elements[position].value=value;

                while(elements[position].previous!=NULL){
                    if(elements[position].value < elements[position].previous->value){
                        int temp=elements[position].value;
                        elements[position].value=elements[position].previous->value;
                        elements[position].previous->value=temp;

                        position=(int) (position-1)/2;
                    }
                    else{
                        break;
                    }
                }

                cout << "Edited!";
            }
        }
        else if(selection==6){     //traverse
            for(int i=0; i<currentPosition; i++){
                printf("%d, ", elements[i].value);
            }
            cout << "\n\n";
        }
        else{                      //exit
            selection=0;
        }

    }

    return 0;
}
