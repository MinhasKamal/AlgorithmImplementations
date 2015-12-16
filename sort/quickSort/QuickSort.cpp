/**
* Programmer: Minhas Kamal (BSSE0509,IIT,DU)
* Date: 15-Nov-2013
**/

#include <iostream>
#include <fstream>

using namespace std;

void quickSort(int *myArray, int left, int right);  //sorts the list
int qSort(int *myArray, int left, int right);   //swaps & places one element at right place

int main()
{
    ifstream list; //input file stream
    list.open("QuickSort_Input.txt");
    //list.open(argv[1]);

    if(!list.is_open()){   //when file is not found
        cout << "File is not found!\n";
        return 0;
    }

    int member;     //number of integers
    list >> member;

    int myArray[member]; //stores the input data
    for(int i=0; i<member; i++)    //reading the data
        list >> myArray[i];

    int left=0, right=member-1;

    if(member>1)
        quickSort(myArray, left, right);


    for(int i=0; i<member; i++)    //printing the data
        cout << myArray[i] << endl;

    list.close();

    return 0;
}

void quickSort(int *myArray, int left, int right)
{
    if(left<right){
        int loc=qSort(myArray, left, right);

        quickSort(myArray, left, loc-1);
        quickSort(myArray, loc+1, right);
    }
    return ;
}

int qSort(int *myArray, int left, int right)
{
    int lock=left;
    while(1){
        while(myArray[lock]<=myArray[right] && lock!=right) //searching from right to left
            right--;
        if(lock==right) break;
        if(myArray[lock]>myArray[right]){
            int temp=myArray[lock]; //swapping
            myArray[lock]=myArray[right];
            myArray[right]=temp;

            lock=right;
        }

        while(myArray[left]<=myArray[lock] && lock!=left) //searching from left to right
            left++;
        if(lock==left) break;
        if(myArray[left]>myArray[lock]){
            int temp=myArray[lock]; //swapping
            myArray[lock]=myArray[left];
            myArray[left]=temp;

            lock=left;
        }
    }
    return lock;
}
