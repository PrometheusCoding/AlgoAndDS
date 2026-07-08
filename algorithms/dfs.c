#include <stdio.h>
#include <stdlib.h>
#include "../dataStructures/myGraphList.c"


int* visitedArray;


void dfs(graphList* graph, int Vertex){

    visitedArray[Vertex] = 1;
    printf("%d ", Vertex);
    node* nodeToTraverse = graph->adjacencyLists[Vertex];

    while(nodeToTraverse){
        if (!visitedArray[nodeToTraverse->vertex]){
            dfs(graph, nodeToTraverse->vertex);
        }

        nodeToTraverse = nodeToTraverse->next;
    }

}

int main(){
    int numOfVertices = 7;
    graphList* directedGraph = createGraph(numOfVertices, 1);
    visitedArray = malloc(sizeof(int) * numOfVertices);

    addEdge(directedGraph, 0, 1);
    addEdge(directedGraph, 1, 2);
    addEdge(directedGraph, 2, 3);
    addEdge(directedGraph, 2, 6);
    addEdge(directedGraph, 1, 4);
    addEdge(directedGraph, 4, 5);
    printGraph(directedGraph);


    for (int iter = 0; iter < numOfVertices; iter++){
        visitedArray[iter] = 0;
    }

    printf("\n");
    printf("DFS OUTPUT: ");
    dfs(directedGraph, 0);
    printf("\n");

    free(visitedArray);
    return 0;
}