#ifndef MYGRAPHLIST_H
#define MYGRAPHLIST_H

typedef struct node
{
    int vertex;
    struct node* next;
}node;


typedef struct
{
    int numOfVertices;
    struct node** adjacencyLists;
    int isDirected;
} graphList;

struct node* createNode(int);
graphList* createGraph(int, int);
void addEdge(graphList*, int, int);
int removeEdge(graphList*, int, int);
void printGraph(graphList*);

#endif