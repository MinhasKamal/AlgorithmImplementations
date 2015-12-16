/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 08.Oct.2013
**/

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()//(int argc, char* argv[])
{
    ifstream graph; //input file stream
    graph.open("TopologicalSort_Input.txt");
    //graph.open(argv[1]);

    if(!graph.is_open()){   //when file is not found
        cout << "File name is wrong!\n";
        return 0;
    }

    int vertexNumber, **matrix;
    graph >> vertexNumber;
    matrix = new int* [vertexNumber];
    for(int i=0; i<vertexNumber; i++)
        matrix[i] = new int [vertexNumber];

    for(int i=0; i<vertexNumber; i++)   //taking the input
        for(int j=0; j<vertexNumber; j++)
            graph >> matrix[i][j];



    /*for(int i=0; i<vertexNumber; i++){  //output of the input file
        for(int j=0; j<vertexNumber; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }*/

    int *colour = new int [vertexNumber];     //colour of the vertex


    for(int i=0; i<vertexNumber; i++)  //initializing the arrays
        colour[i] = 1;       //colour = 1 = white, 2 = grey


    ///start of DFS
    stack<int> sortedList;
    for(int x=0; x<vertexNumber; x++)
        if(colour[x]==1){
            int startVertex=x;
            stack<int> dFSStack;
            dFSStack.push(startVertex);
            sortedList.push(startVertex);

            colour[startVertex]=2;      //colour is set to grey

            while(!dFSStack.empty()){
                int i=dFSStack.top();
                dFSStack.pop();

                for(int j=0; j<vertexNumber; j++)
                    if(matrix[i][j]==1){
                        colour[j]=2;
                        dFSStack.push(j);
                        sortedList.push(j);
                    }
            }
        }

    int result[vertexNumber];
    for(int i=0; i<vertexNumber; i++){  //refreshing the result
        int flag=1;
        while(flag){
            flag=0;
            for(int j=0; j<i && flag==0; j++)
                if(result[j]==sortedList.top()){
                    //cout << sortedList.top() <<"\n";
                    sortedList.pop();
                    flag=1;
                }
            if(flag==0) {
                result[i]=sortedList.top();
                sortedList.pop();
            }
        }
    }


    cout << "Topological Sort: " << endl;   //output of the result
    for(int i=vertexNumber-1; i>=0; i--)
        cout << "\t\t" << result[i]+1 << endl;


    for(int i=0; i<vertexNumber; i++)   //delete the matrix
        delete[] matrix[i];
    delete[] matrix;

    delete[] colour;    //returning the used memory

    graph.close();  //close the file graph

    return 0;
}
