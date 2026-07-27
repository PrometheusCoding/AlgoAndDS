#include <stdlib.h>
#include <stdio.h>
#include "../dataStructures/myGraphMatrix.c"
#include "../dataStructures/myPriorityQueue.c"


graphMatrix* createDijkstrasGraph(graphMatrix* graph, int* distances, int* prevNode){

    int numVerts = graph->numOfVertices;

    printf("Distances: [");
    for (int iter=0; iter<numVerts; iter++){
        printf("%2d: %2d  ", iter, distances[iter]);
    }
    printf("]\n");
    
    printf("PrevNode: [");
    for (int iter=0; iter<numVerts; iter++){
        printf("%2d: %2d  ", iter, prevNode[iter]);
    }
    printf("]\n");

    graphMatrix* dijkstrasGraph = createAdjacencyMatrix(numVerts, 1, 1);

    for (int iter=0; iter<numVerts; iter++){
        if (prevNode[iter] != -1){
            editEdge(dijkstrasGraph, prevNode[iter], iter, 1, graph->matrix[(prevNode[iter] * numVerts) + iter].edgeWeight);
        }
    }

    return dijkstrasGraph;

}

graphMatrix* dijkstras(graphMatrix* graph, int startVertex){

    int numVerts = graph->numOfVertices;
    int visited[numVerts];
    int distances[numVerts];
    int prevNode[numVerts];


    for (int iter = 0; iter<numVerts; iter++){
        visited[iter] = 0;
        distances[iter] = 100000;
        prevNode[iter] = -1;
    }
    distances[startVertex] = 0;

    myPriorityQueue pqueueEdges;
    init(&pqueueEdges, 0);
    queueElement element;
    element.val = startVertex;
    element.priority = 0;
    enqueue(&pqueueEdges, element);



    while (!isEmpty(&pqueueEdges)){
        int currVertex = dequeue(&pqueueEdges).val;
        if (visited[currVertex]){continue;}

        visited[currVertex] = 1;

        for (int iter=0; iter<numVerts; iter++){
            if (visited[iter]){continue;}
            if (graph->matrix[(currVertex * numVerts) + iter].edgeExists){
                int potentialDistance = distances[currVertex] + graph->matrix[(currVertex * numVerts) + iter].edgeWeight;
                if (potentialDistance < distances[iter]){
                    distances[iter] = potentialDistance;
                    prevNode[iter] = currVertex;
                    enqueue(&pqueueEdges, (queueElement){iter, potentialDistance});
                }
            }

        }

    }

    graphMatrix* dijkstrasGraph = createDijkstrasGraph(graph, distances, prevNode);
    printAdjacencyMatrix(dijkstrasGraph);

    return dijkstrasGraph;

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

    dijkstras(graph, 0);

    freeGraph(graph);


    graphMatrix* graphTwo = createAdjacencyMatrix(6, 0, 1);

    editEdge(graphTwo, 0, 1, 1, 7);
    editEdge(graphTwo, 0, 2, 1, 9);
    editEdge(graphTwo, 0, 5, 1, 14);
    editEdge(graphTwo, 1, 2, 1, 10);
    editEdge(graphTwo, 1, 3, 1, 15);
    editEdge(graphTwo, 2, 3, 1, 11);
    editEdge(graphTwo, 2, 5, 1, 2);
    editEdge(graphTwo, 3, 4, 1, 6);
    editEdge(graphTwo, 4, 5, 1, 9);

    printAdjacencyMatrix(graphTwo);
    dijkstras(graphTwo, 0);
    freeGraph(graphTwo);

    return 0;
}