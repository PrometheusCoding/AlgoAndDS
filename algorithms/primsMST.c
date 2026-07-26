#include <stdio.h>
#include <stdlib.h>
#include "../dataStructures/myGraphMatrix.c"

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

void prims(graphMatrix* graph){

    /*
    How to perform the algorithm.
    1. Check to see if the provided graph is undirected and weighted. (Should also check if it is connected tbf)
    2. First pick a random node to start with to create the set of visited vertices, for this case, the
       first node of this graph is fine.
    3. Check all the weights of edges for vertices reachable from the set of visited vertices. Choose the smallest
       edge from the available choices (If two edges have the same weight, the choice is arbitrary).
    4. Repeat steps 2 and 3 until all nodes are visited.
    */

    if (graph->isDirected || !graph->isWeighted){
        printf("Error: Invalid graph was passed. Either it is directed or not weighted!\n");
        return;
    }

    int numVerts = graph->numOfVertices;

    int visited[numVerts]; // Tracks which vertices are in the current tree.
    int key[numVerts]; // The weight of the cheapest edge currently known that connects the vertex to the tree
    int parent[numVerts]; // Tracks which tree vertex the cheapest edge comes from
    
    for (int iter = 0; iter<numVerts; iter++){
        key[iter] = 100000;
        parent[iter] = -1;
        visited[iter] = 0;
    }

    visited[0] = 1;
    int numOfVisited = 1;
    
    for (int iter = 0; iter<numVerts; iter++){
        if (graph->matrix[iter].edgeExists){
            key[iter] = graph->matrix[iter].edgeWeight;
            parent[iter] = 0;
        }
    }

    graphMatrix* MST = createAdjacencyMatrix(numVerts, 0, 1);

    while (numOfVisited != numVerts){
        int vertexWithSmallestEdge = -1;
        int smallestWeight = 10000;

        // Identify which of the edges that connect from the current tree is the smallest.
        for (int iter = 0; iter < numVerts; iter++){
            if (!visited[iter] && key[iter] < smallestWeight){
                smallestWeight = key[iter];
                vertexWithSmallestEdge = iter;
            }
        }

        // Update tracking variables and add the smallest edge to the tree 
        visited[vertexWithSmallestEdge] = 1;
        numOfVisited++;
        editEdge(MST, parent[vertexWithSmallestEdge], vertexWithSmallestEdge, 1, key[vertexWithSmallestEdge]);

        // Update the key and parent values if the adding of the new vertex provides a cheaper edge to the tree.
        for (int iter = 0; iter < numVerts; iter++){
            if (!visited[iter] && graph->matrix[(vertexWithSmallestEdge * numVerts) + iter].edgeExists){
                int weight = graph->matrix[(vertexWithSmallestEdge * numVerts) + iter].edgeWeight;
                if (weight < key[iter]){
                    key[iter] = weight;
                    parent[iter] = vertexWithSmallestEdge; 
                }
            }
        }
    }


    printMST(MST);

    return;
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

    prims(graph);

    return 0;
}