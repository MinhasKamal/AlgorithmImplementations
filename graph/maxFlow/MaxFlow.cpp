/**
* Name: Minhas Kamal
* Date: 24-Mar-2014
**/


#include <iostream>
#include <fstream>
#include <queue>

using namespace std;


int FordFulkerson(int **matrix, int vertexNumber, int s, int t);
bool BFS(int **residualGraph, int vertexNumber, int s, int t, int parent[]);


int main(){
    ifstream graph; //input file stream
    graph.open("MaxFlow_Input.txt");

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

    graph.close();  //close the file graph

    /*for(int i=0; i<vertexNumber; i++){   ///test
        for(int j=0; j<vertexNumber; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }*/

    cout << "So max flow is: " << FordFulkerson(matrix, vertexNumber, 0, 5);


    return 0;
}


//FordFulkerson algorithm
int FordFulkerson(int **matrix, int vertexNumber, int s, int t){
    int **residualGraph;
    residualGraph = new int*[vertexNumber];
    for(int i=0; i<vertexNumber; i++)
        residualGraph[i] = new int[vertexNumber];


    for(int i=0; i<vertexNumber; i++)
        for (int j=0; j<vertexNumber; j++)
             residualGraph[i][j]=matrix[i][j];

    int parent[vertexNumber];

    int maxFlow=0;

    while( BFS(residualGraph, vertexNumber, s, t, parent) ){
        int pathFlow = 99999;
        for(int v=t; v!=s; v=parent[v]){
            if(pathFlow > residualGraph[parent[v]][v]){
                pathFlow=residualGraph[parent[v]][v];
            }
        }


        for(int v=t; v!=s; v=parent[v]){
            residualGraph[parent[v]][v] = residualGraph[parent[v]][v] - pathFlow;
            residualGraph[v][parent[v]] = residualGraph[parent[v]][v] + pathFlow;
        }

        maxFlow = maxFlow+pathFlow;
    }

    return maxFlow;
}


//classic BFS
bool BFS(int **residualGraph, int vertexNumber, int s, int t, int parent[]){

    bool visited[vertexNumber];
    for(int i=0; i<vertexNumber; i++){
        visited[i]=false;
    }

    queue<int> vertexQueue;

    vertexQueue.push(s);
    parent[s]=-1;
    visited[s]=true;

    while(!vertexQueue.empty()){
        int v=vertexQueue.front();
        vertexQueue.pop();

        for(int i=0; i<vertexNumber; i++){
            if(visited[i]==false && residualGraph[v][i]>0){
                vertexQueue.push(i);
                parent[i]=v;
                visited[i]=true;
            }
        }
    }

    return visited[t];
}

