#ifndef MYGRAPHMATRIX_H
#define MYGRAPHMATRIX

typedef struct graphMatrix{
    int* matrix;
    int numOfVertices;
    int isDirected;
} graphMatrix;

graphMatrix* createAdjacencyMatrix(int, int);
void editEdge(graphMatrix*, int, int, int);
void printAdjacencyMatrix(graphMatrix*);

#endif