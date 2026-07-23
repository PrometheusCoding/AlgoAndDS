#include <stdio.h>
#include <stdlib.h>
#include "../dataStructures/myGraphList.c"
#include "../dataStructures/myQueue.c"

void topologicalSort(graphList* graph){
    /*
    Function currently assumes that the graph passed IS A DAG

    1. Initialise an array counts and get the number of incoming arcs for each node
    2. Initialise the Queue needed to perform topological ordering
    3. Iterate through the counts array and for any vertex where it is 0, enqueue it
    4. While the queue is not empty, remove the first element of the queue and then
       go through that vertex's outgoing neighbours and for each outgoing neighbour
       reduce its count in the counts array. If the new count for the outgoing neigbour
       becomes 0, enqueue it.
    */
    int numOfVerts = graph->numOfVertices;
    int counts[numOfVerts];
    for (int iter=0; iter<numOfVerts; iter++){
        counts[iter] = 0;
    }

    for (int iter = 0; iter<numOfVerts; iter++){
        node* temp = graph->adjacencyLists[iter];
        while(temp){
            counts[temp->vertex]++;
            temp = temp->next;
        }
    }

    myQueue Queue;
    init(&Queue);

    for (int iter = 0; iter<numOfVerts; iter++){
        if (counts[iter] == 0){
            enqueue(&Queue, iter);
        }
    }

    printf("TOPOLOGICAL SORT FOR THIS GRAPH IS:\n");
    while(!isEmpty(&Queue)){
        int removedVertex = dequeue(&Queue);
        printf("%d ", removedVertex);

        node* temp = graph->adjacencyLists[removedVertex];
        while(temp){
            counts[temp->vertex]--;
            if (counts[temp->vertex] == 0){enqueue(&Queue, temp->vertex);}
            temp = temp->next;
        }
    }

    printf("\n");



}

int main(){

    graphList* DAG = createGraph(7, 1);

    addEdge(DAG, 0, 1);
    addEdge(DAG, 0, 2);
    addEdge(DAG, 0, 3);
    addEdge(DAG, 1, 3);
    addEdge(DAG, 1, 4);
    addEdge(DAG, 2, 5);
    addEdge(DAG, 3, 2);
    addEdge(DAG, 3, 5);
    addEdge(DAG, 4, 3);
    addEdge(DAG, 6, 3);
    addEdge(DAG, 6, 4);

    printf("Adjacency list for DAG\n");
    printGraph(DAG);

    topologicalSort(DAG);



    return 0;
}