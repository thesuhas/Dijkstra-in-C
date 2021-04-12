#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Node struct
typedef struct Node
{
    // Having vertex ID
    int id;
    // Weight of connection
    int weight;
    // Next pointer
    struct Node* next;
    // Distance of path
    int dist;
    // ID of previous vertex
    int prev;
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

// Heap
typedef struct Heap
{
    int n;
    Node** heap;
} Heap;

// Function to initialise a graph
Graph* initialise(int size);

// Function to do file handling
Graph* file(void);

// Inserting graphs to adj list
Head insert(Head head, int id, int weight);

// Displaying graph
void display(Graph* g);

// Creation of heap
Heap* create_heap(int size);