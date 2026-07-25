#include <stdlib.h>
#include <stdio.h>
#include "myGraphMatrix.h"


graphMatrix* createAdjacencyMatrix(int numOfVertices, int isDirected, int isWeighted){

    graphMatrix* newGraphMatrix = malloc(sizeof(graphMatrix));
    newGraphMatrix->numOfVertices = numOfVertices;
    newGraphMatrix->isDirected = isDirected;
    newGraphMatrix->isWeighted = isWeighted;

    newGraphMatrix->matrix = malloc(numOfVertices*numOfVertices*sizeof(graphElement));

    for (int iter = 0; iter < numOfVertices*numOfVertices; iter++){
        newGraphMatrix->matrix[iter].edgeExists = 0;
        newGraphMatrix->matrix[iter].edgeWeight = -10000;
    }


    return newGraphMatrix;

}

static int editEdgeDirected(graphMatrix* graph, int tail, int head, int add, int weight){

    graph->matrix[(tail * graph->numOfVertices) + head].edgeExists = add;
    if (graph->isWeighted && add){
        graph->matrix[(tail * graph->numOfVertices) + head].edgeWeight = weight;
    } else {
        graph->matrix[(tail * graph->numOfVertices) + head].edgeWeight = -10000;
    }
} 

int editEdge(graphMatrix* graph, int tail, int head, int add, int weight){
    int isSuccess = editEdgeDirected(graph, tail, head, add, weight);

    if (isSuccess && !graph->isDirected){
        isSuccess = editEdgeDirected(graph, head, tail, add, weight);
    }

    return isSuccess;
}

void printAdjacencyMatrix(graphMatrix* graph){
    printf("Matrix is being printed!");
    for (int iter = 0; iter < graph->numOfVertices * graph->numOfVertices; iter++){
        if (iter % graph->numOfVertices == 0){printf("\n");}

        if (graph->isWeighted){
            printf("%3d(%6d) ", graph->matrix[iter].edgeExists, graph->matrix[iter].edgeWeight);
        } else {
            printf("%d", graph->matrix[iter].edgeExists);
        }

    }
    printf("\n");
}

#ifdef MYGRAPHMATRIX_TEST
int main(){
    graphMatrix* undirectedGraph = createAdjacencyMatrix(5, 0, 0);
    editEdge(undirectedGraph, 0, 2, 1, 0);
    editEdge(undirectedGraph, 1, 3, 1, 0);
    editEdge(undirectedGraph, 3, 4, 1, 0);
    editEdge(undirectedGraph, 0, 1, 1, 0);
    printAdjacencyMatrix(undirectedGraph);

    editEdge(undirectedGraph, 1, 3, 0, 0);
    printAdjacencyMatrix(undirectedGraph);

    graphMatrix* directedGraph = createAdjacencyMatrix(4, 1, 1);
    editEdge(directedGraph, 1, 0, 1, 22);
    editEdge(directedGraph, 1, 2, 1, 43);
    editEdge(directedGraph, 2, 0, 1, 32);
    editEdge(directedGraph, 0, 3, 1, 12);
    printAdjacencyMatrix(directedGraph);

    editEdge(directedGraph, 1, 0, 0, 0);
    printAdjacencyMatrix(directedGraph);

    return 0;
}
#endif