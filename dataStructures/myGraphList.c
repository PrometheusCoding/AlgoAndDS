#include <stdlib.h>
#include <stdio.h>
#include "myGraphList.h"

node* createNode(int vertex){
    node* newNode = malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

graphList* createGraph(int numOfVertices, int isDirected){

    // 1. Create the instance of the graph and assign values to numOfVertices and isDirected
    // 2. Assign memory for creating the adjacency lists
    // 3. Initialise each adjacency list as empty
    // 4. Return the graph generated

    graphList* newGraph = malloc(sizeof(graphList));
    newGraph->numOfVertices = numOfVertices;
    newGraph->isDirected = isDirected;

    newGraph->adjacencyLists = malloc(numOfVertices * sizeof(node*));

    for (int iter = 0; iter < numOfVertices; iter++){
        newGraph->adjacencyLists[iter] = NULL;
    }

    return newGraph;
}

void addEdge(graphList* graph, int tail, int head){
    node* newNode = createNode(head);
    newNode->next = graph->adjacencyLists[tail];
    graph->adjacencyLists[tail] = newNode;

    if (!graph->isDirected){
        newNode = createNode(tail);
        newNode->next = graph->adjacencyLists[head];
        graph->adjacencyLists[head] = newNode;
    }
}

static int removeEdgeDirected(graphList* graph, int tail, int head){
    node* nodeToSearch = graph->adjacencyLists[tail];
    node* prevNode = NULL;
    
    while(nodeToSearch){
        if (nodeToSearch->vertex == head){
            
            if (prevNode == NULL){
                graph->adjacencyLists[tail] = nodeToSearch->next;
            } else {
                prevNode->next = nodeToSearch->next;
            }
            free(nodeToSearch);
            return 1;

        } else {
            prevNode = nodeToSearch;
            nodeToSearch = nodeToSearch->next;
        }
    }
    return -1;
}

int removeEdge(graphList* graph, int tail, int head){
    int result = removeEdgeDirected(graph, tail, head);
    
    if (result == 1 && !graph->isDirected){
        removeEdgeDirected(graph, head, tail);
    }

    return result;
}

void printGraph(graphList* graph){
    printf("Vertex:     Adjacency List\n");
    for (int iter=0; iter<graph->numOfVertices; iter++){
        node* temp = graph->adjacencyLists[iter];
        printf("%d:     ", iter);

        while (temp){
            printf("%d -> ", temp->vertex);
            temp=temp->next;
        }

        printf(" NULL\n");
    }
}

#ifdef GRAPHLIST_TEST
int main(){
    graphList* undirectedGraph = createGraph(5, 0);
    addEdge(undirectedGraph, 0, 1);
    addEdge(undirectedGraph, 0, 2);
    addEdge(undirectedGraph, 1, 3);
    addEdge(undirectedGraph, 3, 4);
    if (removeEdge(undirectedGraph, 0, 2)){
        printf("Edge was successfully removed!\n");
    }


    printf("Adjacecncy List for Undirected Graph:\n");
    printGraph(undirectedGraph);

    graphList* directedGraph = createGraph(4, 1);
    addEdge(directedGraph, 1, 0);
    addEdge(directedGraph, 1, 2);
    addEdge(directedGraph, 2, 0);
    addEdge(directedGraph, 0, 3);

    printf("\nAdjacecncy List for Directed Graph:\n");
    printGraph(directedGraph);

    return 0;
}
#endif