#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node struct
typedef struct Node
{
    // Having vertex ID
    int id;
    // Weight of connection
    int weight;
    // Next pointer
    struct Node* next;
} Node;

// Node header
typedef struct Head
{
    Node* head;
} Head;

// Adjlist
typedef struct Graph
{
    int n;
    Head* graph;
} Graph;

// Function to initialise a graph
Graph* initialise(int size);

// Function to do file handling
Graph* file(void);

// Inserting graphs to adj list
Head insert(Head head, int id, int weight);

// Displaying graph
void display(Graph* g);