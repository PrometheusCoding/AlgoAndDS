#include <stdio.h>
#include <stdlib.h>
#include "../dataStructures/myGraphList.c"
#include "../dataStructures/myQueue.c"

int bfs(graphList* graph, int startVertex){
    // Note, this only works for connected graphs as it doesn't take
    // into account whether ALL vertices have been visited.
    myQueue queue;
    init(&queue);

    int visitedArray[graph->numOfVertices];
    for (int iter = 0; iter < graph->numOfVertices; iter++){
        visitedArray[iter] = 0;
    }

    enqueue(&queue, startVertex);
    visitedArray[startVertex] = 1;
    printf("BFS OUPUT: ");

    while(!isEmpty(&queue)){

        int removedVertex = dequeue(&queue);
        printf("%d ", removedVertex);

        node* nodeToTraverse = graph->adjacencyLists[removedVertex];
        while (nodeToTraverse){
            if (!visitedArray[nodeToTraverse->vertex]){
                enqueue(&queue ,nodeToTraverse->vertex);
                visitedArray[nodeToTraverse->vertex] = 1;

            }
            nodeToTraverse = nodeToTraverse->next;
        }

    }
    printf("\n");
    return 0;

}

int main(){

    int numOfVertices = 5;
    graphList* directedGraph = createGraph(numOfVertices, 1);

    addEdge(directedGraph, 1, 0);
    addEdge(directedGraph, 1, 2);
    addEdge(directedGraph, 2, 0);
    addEdge(directedGraph, 0, 3);
    addEdge(directedGraph, 4, 3);
    addEdge(directedGraph, 3, 4);


    printGraph(directedGraph);

    bfs(directedGraph, 1);

    return 0;
}