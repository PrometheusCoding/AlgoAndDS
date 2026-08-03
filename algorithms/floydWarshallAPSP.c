#include <stdio.h>
#include <stdlib.h>
#include "../dataStructures/myGraphMatrix.c"

int floydWarshallAPSP(graphMatrix* graph){
    int numVerts = graph->numOfVertices;

    int fwGraphWeights[numVerts][numVerts];
    for (int iter = 0; iter<numVerts; iter++){
        for (int iterTwo = 0; iterTwo<numVerts; iterTwo++){

            if (iter == iterTwo){fwGraphWeights[iter][iterTwo] = 0;}
            
            else{
            
                if (graph->matrix[(iter*numVerts) + iterTwo].edgeExists){
                    fwGraphWeights[iter][iterTwo] = graph->matrix[(iter*numVerts) + iterTwo].edgeWeight;
                } else {
                    fwGraphWeights[iter][iterTwo] = 1000000;
                }
            
            }
        }

    }

    for (int iter = 0; iter < numVerts; iter++){ // iter  is our m vertex
        for (int iterTwo = 0; iterTwo < numVerts; iterTwo++){ // iterTwo is our i vertex

            if (iterTwo == iter){continue;}
            
            for (int iterThree = 0; iterThree < numVerts; iterThree++){ // iterThree is our j vertex
            
                if (iterThree == iter || iterThree == iterTwo){continue;}
                int potentialMinWeight = fwGraphWeights[iterTwo][iter] + fwGraphWeights[iter][iterThree];

                if (potentialMinWeight < fwGraphWeights[iterTwo][iterThree]){
                    fwGraphWeights[iterTwo][iterThree] = potentialMinWeight;
                }
            }

        }
    }

    for (int iter = 0; iter<numVerts; iter++){
        printf("\n");
        for (int iterTwo = 0; iterTwo<numVerts; iterTwo++){
            printf("%8d ", fwGraphWeights[iter][iterTwo]);
        }

    }

    printf("\n");
}

int main(){
    
    graphMatrix* graph = createAdjacencyMatrix(8, 1, 1);

    editEdge(graph, 0, 1, 1, 4);
    editEdge(graph, 0, 2, 1, 16);
    editEdge(graph, 0, 3, 1, 6);
    editEdge(graph, 1, 4, 1, 24);
    editEdge(graph, 2, 3, 1, 8);
    editEdge(graph, 2, 5, 1, 10);
    editEdge(graph, 2, 7, 1, 21);
    editEdge(graph, 3, 4, 1, 23);
    editEdge(graph, 3, 5, 1, 5);
    editEdge(graph, 4, 5, 1, 18);
    editEdge(graph, 4, 6, 1, 9);
    editEdge(graph, 5, 6, 1, 11);
    editEdge(graph, 5, 7, 1, 14);
    editEdge(graph, 6, 7, 1, 7);

    printAdjacencyMatrix(graph);

    floydWarshallAPSP(graph);

    freeGraph(graph);
}

