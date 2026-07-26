#include <stdio.h>
#include <stdlib.h>
#include "../dataStructures/myGraphMatrix.c"

typedef struct edge {
    int head;
    int tail;
    int weight;
}edge;

void printMST(graphMatrix* MST){
    int totalWeight = 0;

    for (int iter = 0; iter < MST->numOfVertices; iter++){
        for (int iterTwo = iter + 1; iterTwo < MST->numOfVertices; iterTwo++){
            graphElement entry = MST->matrix[(iter * MST->numOfVertices) + iterTwo];
            if (entry.edgeExists){
                printf("%d - %d : weight %d\n", iter, iterTwo, entry.edgeWeight);
                totalWeight += entry.edgeWeight;
            }
        }
    }

    printf("Total MST weight: %d\n", totalWeight);
}

int getNumberOfEdges(graphMatrix* graph){
    int numOfEdges = 0;

    for(int iter = 0; iter < graph->numOfVertices; iter++){
        for (int iterTwo = 0; iterTwo < graph->numOfVertices; iterTwo++){

            if (graph->matrix[(iter*graph->numOfVertices) + iterTwo].edgeExists){numOfEdges++;}

        }
    }

    numOfEdges = graph->isDirected ? numOfEdges: numOfEdges/2;
    return numOfEdges;
}

int compareWeights(const void* a,  const void* b){
    return (((edge*)a)->weight - ((edge*)b)->weight);
}


int find(int vertex, int* parent){

    /*
    What does find do?
    Checks to see if the current vertex isn't connected to itself. If it isn't recursively move towards the root.
    */

    if (parent[vertex] != vertex){
        parent[vertex] = find(parent[vertex], parent);
    }

    return parent[vertex];
}

int unionOfVertices(int vertexOne, int vertexTwo, int* parent, int* rank){

    /*
    What does union do?

    Checks to see if the two vertices aren't part of the same "tree" already. If they are, adding the edge
    between these two vertices would create a cycle.

    If they aren't, depending on which is of the higher rank, change the parent of the lower one to the higher one.
    If they are of the same rank, then change vertexTwo's parent to the parent of vertexOne and increase the rank
    of vertexOne.
    */

    int rootOfVertexOne = find(vertexOne, parent);
    int rootOfVertexTwo = find(vertexTwo, parent);

    if (rootOfVertexOne == rootOfVertexTwo){
        return 0; // Cycle detected.
    }

    if (rank[rootOfVertexOne] < rank[rootOfVertexTwo]){
        parent[rootOfVertexOne] = rootOfVertexTwo;
    } else if (rank[rootOfVertexOne] > rank[rootOfVertexTwo]){
        parent[rootOfVertexTwo] = rootOfVertexOne;
    } else {
        parent[rootOfVertexTwo] = rootOfVertexOne;
        rank[rootOfVertexOne] ++;
    }

    return 1;

}

int kruskals(graphMatrix* graph){

    /*
    How to perform the algorithm.
    1. Check to see if the provided graph is undirected and weighted. (Should also check if it is connected tbf)
    2. Order the edge weights in ascending order.
    3. Choose the smallest edge weight from that ordered list. If this edge creates a cycle, skip. Else, add the
       edge.
    4. Repeat steps 3 until either n-1 edges have been added or all edges have been exhausted.
    */

    if (graph->isDirected || !graph->isWeighted){
        printf("Error: Invalid graph was passed. Either it is directed or not weighted!\n");
        return -1;
    }

    int numVerts = graph->numOfVertices;
    int numOfEdges = getNumberOfEdges(graph);

    int parent[numVerts]; // Which vertex is the current vertex connected to.
    int rank[numVerts]; // The "height" of the tree if the vertex was the root of the component it is currently in.
    edge edges[numOfEdges];

    int edgesAccountedFor = 0;

    for (int iter = 0; iter < numVerts; iter++){
        parent[iter] = iter;
        rank[iter] = 0;
    }

    for (int iter = 0; iter < numVerts; iter++){
        for (int iterTwo = iter + 1; iterTwo < numVerts; iterTwo++){
            graphElement entry = graph->matrix[(iter * numVerts) + iterTwo];
            if (entry.edgeExists){
                edges[edgesAccountedFor].head = iter;
                edges[edgesAccountedFor].tail = iterTwo;
                edges[edgesAccountedFor].weight =  graph->matrix[(iter*numVerts)+iterTwo].edgeWeight;

                edgesAccountedFor++;
            }
        }
    }


    qsort(edges, numOfEdges, sizeof(edge), compareWeights);


    graphMatrix* MST = createAdjacencyMatrix(numVerts, 0, 1);


    int edgesAdded = 0;
    int iter = 0;

    // 
    while (edgesAdded < numVerts - 1 && iter < numOfEdges){ // if the number of edges is exceeded and n-1
                                                            // edges aren't reached, then the graph is disconnected.
        edge smallestEdge = edges[iter];
        iter++;

        if (unionOfVertices(smallestEdge.tail, smallestEdge.head, parent, rank)){
            editEdge(MST, smallestEdge.tail, smallestEdge.head, 1, smallestEdge.weight);
            edgesAdded++;
        }
    }

    if (edgesAdded < numVerts - 1){return -1;}

    printMST(MST);
    freeGraph(MST);

    return 1;
}

int main(){
    graphMatrix* graph = createAdjacencyMatrix(8, 0, 1);

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

    kruskals(graph);

    freeGraph(graph);

    return 0;
}