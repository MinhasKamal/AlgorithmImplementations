/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 13.Nov.2013
**/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream list; //input file stream
    list.open("BinarySearch_Input.txt");
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

    ///BinarySearch
    int element;
    cout << "Enter the element: ";
    cin >> element;

    int left=0, //left location of the myArray
        right=member-1, //right location of the myArray
        location=-1;    //the location of the element

    while(right-left > 0){
        int loc = (right+left)/2;

        if(myArray[loc]==element){
            location=loc;
            break;
        }
        else if(myArray[loc]>element){
            right = loc-1;
        }
        else if(myArray[loc]<element){
            left = loc+1;
        }
    }

    if(location==-1) {
        cout << "\nElement is not found! \n";
    }
    else{
        //cout << "\nThe location is: " << location+1 << endl;
        cout << "\n\n";
        for(int i=left; i<=right; i++){
            if(myArray[i]==element) cout << "The location is: " << i+1 << endl;
        }
    }

    list.close();

    return 0;
}
