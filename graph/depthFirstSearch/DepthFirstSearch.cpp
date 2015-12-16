/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 13.Nov.2013
**/

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()//(int argc, char* argv[])
{
    ifstream graph; //input file stream
    graph.open("DepthFirstSearch_Input.txt");
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



    /*/for(int i=0; i<vertexNumber; i++){  //output of the input file
        for(int j=0; j<vertexNumber; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }/**/

    int *colour = new int [vertexNumber];   //colour of the vertex


    for(int i=0; i<vertexNumber; i++)  //initializing the arrays
        colour[i] = 1;       //colour = 1 = white, 2 = grey


    int startVertex;    //taking input from the user as [1-vertexNumber] & making it as [0-vertexNumber-1]
    cout << "# Enter the starting vertex[1-" << vertexNumber << "]: ";
	cin >> startVertex;
	startVertex = startVertex-1;

    ///start of DFS
    stack<int> dFSStack;
    dFSStack.push(startVertex);

    colour[startVertex]=2;      //colour is set to grey

    cout << "Reachable vertexes are: \n";
    while(!dFSStack.empty()){
		int i=dFSStack.top();
		dFSStack.pop();

		for(int j=0; j<vertexNumber; j++)
			if(matrix[i][j]==1 && colour[j]==1){
                colour[j]=2;
                dFSStack.push(j);
            }
            cout << "\t\t\t" << i+1 << endl;
	}


    for(int i=0; i<vertexNumber; i++)   //delete the matrix
        delete[] matrix[i];
    delete[] matrix;

    delete[] colour;    //returning the used memory

    graph.close();  //close the file graph

    return 0;
}


