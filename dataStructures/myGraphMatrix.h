#ifndef MYGRAPHMATRIX_H
#define MYGRAPHMATRIX

typedef struct graphElement{

    int edgeExists;
    int edgeWeight;

} graphElement;

typedef struct graphMatrix{
    graphElement* matrix;
    int numOfVertices;
    int isDirected;
    int isWeighted;
} graphMatrix;

graphMatrix* createAdjacencyMatrix(int, int, int);
int editEdge(graphMatrix*, int, int, int, int);
void printAdjacencyMatrix(graphMatrix*);

#endif