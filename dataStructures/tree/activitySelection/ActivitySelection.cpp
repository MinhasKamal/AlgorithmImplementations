/**
* Programmer: Minhas Kamal (BSSE0509,IIT,DU)
* Date: 14-Mar-2014
**/


#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    //**taking the file name
    string fileName="";
    if(argc>1){
        fileName=argv[1];
    }else{
        cout << "Enter the file name: ";
        cin >> fileName;
        //fileName="ASInput.txt";//test
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
    int n;
    input >> n;
    int time[n][3]; ///colour, start position, stop position

    int i=0;
    for(; i<n; i++){
        time[i][0]=0;
        input >> time[i][1] >> time[i][2];
    }
    input.close();


    /*////test
    int t;
    cout << endl;
    for(t=0; t<n; t++)
        cout << time[t][0] <<" "<< time[t][1] <<" "<< time[t][2] << endl;
    /**/

    int least,
        leastIndex,
        totalActivity=0;
    while(1){
        least=100000, leastIndex=-1;
        for(i=0; i<n; i++){
            if(time[i][0]==0){
                if(time[i][2]<least){
                    least=time[i][2];
                    leastIndex=i;
                }
            }
        }

        if(leastIndex==-1){
            break;
        }
        totalActivity++;
        cout << "Work index is: "<< leastIndex+1 <<endl;
        time[leastIndex][0]=1;

        for(i=0; i<n; i++){
            if(time[i][1]<time[leastIndex][2]){
                time[i][0]=1;
            }
        }
    }

    cout << endl << "So total activities are: " << totalActivity << endl;

    return 0;
}

