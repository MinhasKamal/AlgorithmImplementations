/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 12.Nov.2013
**/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void printPath(int* colour, int* distance, int* previous, int startVertex, int queryVertex);

int main()//(int argc, char* argv[])
{
    ifstream graph; //input file stream
    graph.open("BreadthFirstSearch_Input2.txt");
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

    int *colour = new int [vertexNumber],     //colour of the vertex
        *previous = new int [vertexNumber],  //the previous vertex
        *distance = new int [vertexNumber];      //distance of the vertex


    for(int i=0; i<vertexNumber; i++){  //initializing the arrays
        colour[i] = 1;       //colour = 1 = white, 2 = grey, 3 = black
		previous[i] = -1;   //initializing with a value that won't come after the program is run
		distance[i] = -10;   //initializing with a value that won't come after the program is run
    }

    int startVertex;    //taking input from the user as [1-5] & making it as [1-4]
    cout << "# Enter the starting vertex[1-" << vertexNumber << "]: ";
	cin >> startVertex;
	startVertex = startVertex-1;

    ///Start of BFS
    queue<int> bFSQueue;
    bFSQueue.push(startVertex);

    colour[startVertex]=2;      //colour is set to grey
    distance[startVertex]=0;    //distance is zero
	previous[startVertex]=-2;  //there is no previous

    while(!bFSQueue.empty()){   //finding adjacent vertexes and colouring them
		int i=bFSQueue.front();
		bFSQueue.pop();
		colour[i]=3;

		for(int j=0; j<vertexNumber; j++)
			if(matrix[i][j]==1 && colour[j]==1){
                    colour[j]=2;
					distance[j]=distance[i]+1;
					previous[j] =i;
					bFSQueue.push(j);
				}
	}


    /*cout << endl;
	for(int i=0; i<vertexNumber; i++)   //output of the BFS
        cout << colour[i] << "\t" << distance[i] << "\t" << previous[i]+1 << "\n";
	cout << endl;*/

    int queryVertex;
    cout << "# Enter the query vertex[1-" << vertexNumber << "]: ";
	cin >> queryVertex;
	queryVertex = queryVertex-1;

	cout << "\n\nThe Path is: \n";
	printPath(colour, distance, previous, startVertex, queryVertex);


    for(int i=0; i<vertexNumber; i++)   //delete the matrix
        delete[] matrix[i];
    delete[] matrix;

    delete[] colour;    //returning the used memory
    delete[] distance;
	delete[] previous;

    graph.close();  //close the file graph

    return 0;
}

void printPath(int* colour, int* distance, int* previous, int startVertex, int queryVertex)
{
	if(startVertex==queryVertex)
		cout << "\t\t" << queryVertex+1 << endl;
	else if (previous[queryVertex]==-1)
		cout << "There is no path!\n";
	else{
		printPath(colour, distance, previous, startVertex, previous[queryVertex]); //recursion
		cout << "\t\t" << queryVertex+1 << endl; //printing each vertex
	}
}

