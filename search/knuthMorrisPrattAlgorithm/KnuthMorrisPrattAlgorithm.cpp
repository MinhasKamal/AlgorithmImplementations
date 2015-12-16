/**
* Programmer: Minhas Kamal (BSSE0509,IIT,DU)
* Date: 21-02-2014
**/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int KMPAlgorithm(string wholeFileString, string subFileString);
void FailureFunction(string subFileString, int* F);


int main(int argc, char *argv[]){
    //**taking the file name
    string fileName="";
    if(argc>1){
        fileName=argv[1];
    }else{
        cout << "Enter the file name: ";
        cin >> fileName;
        //fileName="KMPInput.txt";//test
    }


    //**opening the file
    ifstream input;
    input.open(fileName.c_str());
    if(!input.is_open()){   //when the file name is wrong
        printf("Sorry the file is not found!");
        input.close();
        return 1;
    }


    //**reading file
    string wholeFileString="";
    string subString="";
    input >> wholeFileString;
    while(!input.eof()){
        input >> subString;

        wholeFileString.append(" "+subString);
    }
    //cout << wholeFileString;//test
    input.close();


    //**taking the input of sub string
    string subFileString="";
    cout << "Enter your sub string: ";
    cin >> subFileString;
    //cout << subFileString;//test


    //**finding the position of sub string
    int startPosition=-1;

    //KMP Algorithm
    if(subFileString.length()<=wholeFileString.length()){
        startPosition=KMPAlgorithm(wholeFileString, subFileString);
    }else{
        startPosition=-2;
    }


    //**position output
    if(startPosition==-2){
        cout << "The sub string is larger!\n\n";
    }else if(startPosition==-1){
        cout << "The sub string is not found!\n\n";
    }else{
        cout << "The position of the sub string is: " << ++startPosition << "\n\n";
    }


    return 0;
}


//searching algorithm
int KMPAlgorithm(string wholeFileString, string subFileString){
    int position=-1;

    int wholeFileStringLength=wholeFileString.length(),
        subFileStringLength=subFileString.length();

    int F[subFileStringLength];
    FailureFunction(subFileString, F);

    /*///test
    int k=0;
    for(; k<subFileStringLength; k++){
        printf("%d ", F[k]);
    }printf("\n");
    /**/

    int i, j=0;
    for(i=0; i<wholeFileStringLength; i++){
        while(j>0 && subFileString[j]!=wholeFileString[i]){
            j=F[j-1];
        }

        if(subFileString[j]==wholeFileString[i]){
            j++;
        }

        if(j==subFileStringLength){
            position=i-subFileStringLength+1;
            break;
        }
    }


    return position;
}

//failure function
void FailureFunction(string String, int* F){
    int StringLength=String.length();
    int value=0;
    F[0]=value;

    int i;
    for(i=1; i<StringLength; i++){
        while(value>0 && String[value]!=String[i]){
            value=F[value-1];
        }

        if(String[value]==String[i]){
            value=value+1;
        }

        F[i]=value;
    }


    return;
}



