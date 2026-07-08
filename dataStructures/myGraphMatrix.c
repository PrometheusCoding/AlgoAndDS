#include <stdlib.h>
#include <stdio.h>
#include "myGraphMatrix.h"


graphMatrix* createAdjacencyMatrix(int numOfVertices, int isDirected){

    graphMatrix* newGraphMatrix = malloc(sizeof(graphMatrix));
    newGraphMatrix->numOfVertices = numOfVertices;
    newGraphMatrix->isDirected = isDirected;

    newGraphMatrix->matrix = malloc(numOfVertices*numOfVertices*sizeof(int));

    for (int iter = 0; iter < numOfVertices*numOfVertices; iter++){
        newGraphMatrix->matrix[iter] = 0;
    }


    return newGraphMatrix;

}

void editEdge(graphMatrix* graph, int tail, int head, int add){
    graph->matrix[(tail * graph->numOfVertices) + head] = add;
    if (!graph->isDirected){graph->matrix[(head * graph->numOfVertices) + tail] = add;}
}

void printAdjacencyMatrix(graphMatrix* graph){
    printf("Matrix is being printed!");
    for (int iter = 0; iter < graph->numOfVertices * graph->numOfVertices; iter++){
        if (iter % graph->numOfVertices == 0){printf("\n");}
        printf("%d", graph->matrix[iter]);
    }
    printf("\n");
}

#ifdef MYGRAPHMATRIX_TEST
int main(){
    graphMatrix* undirectedGraph = createAdjacencyMatrix(5, 0);
    editEdge(undirectedGraph, 0, 2, 1);
    editEdge(undirectedGraph, 1, 3, 1);
    editEdge(undirectedGraph, 3, 4, 1);
    editEdge(undirectedGraph, 0, 1, 1);
    printAdjacencyMatrix(undirectedGraph);

    editEdge(undirectedGraph, 1, 3, 0);
    printAdjacencyMatrix(undirectedGraph);

    graphMatrix* directedGraph = createAdjacencyMatrix(4, 1);
    editEdge(directedGraph, 1, 0, 1);
    editEdge(directedGraph, 1, 2, 1);
    editEdge(directedGraph, 2, 0, 1);
    editEdge(directedGraph, 0, 3, 1);
    printAdjacencyMatrix(directedGraph);

    editEdge(directedGraph, 1, 0, 0);
    printAdjacencyMatrix(directedGraph);

    return 0;
}
#endif