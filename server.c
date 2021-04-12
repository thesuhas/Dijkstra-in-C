#include "server.h"

Graph* initialise(int size)
{
    // Create a graph
    Graph* g = (Graph *)malloc(sizeof(Graph));

    g->n = size;
    g->graph = malloc(size * sizeof(Node));

    // Initialise each node to NULL
    for (int i = 0; i < size; i ++)
    {
        g->graph[i].head = NULL;
    }

    return g;
}

Head insert(Head head, int id, int weight)
{
    // Create node with id and weight
    Node* new = malloc(sizeof(Node));
    new->id = id;
    new->weight = weight;
    new->next = NULL;
    new->dist = INT_MAX;
    new->prev = 0; // Setting to 0 as nodes start from 1

    // If that particular list is empty
    if (head.head == NULL)
    {
        head.head = new;
    }
    else
    {
        Node* temp = head.head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Now at last node, next node will be new node
        temp->next = new;
    }
    return head;
}

Graph* file(void)
{
    // Read data from file
    FILE* fp;

    fp = fopen("adjacencylist.txt", "r");

    // If file pointer is null, return
    if (fp == NULL)
    {
        return NULL;
    }

    size_t size = 100;

    // Create string to display
    char* test = malloc(100 * sizeof(char));
    int x;

    x = getline(&test, &size, fp);

    // Here test is first line, which is number of vertices in graph
    Graph* g = initialise(atoi(test) + 1); // Adding 1 so can refer with vertex ids instead of converting to indices

    // Iterate through all connections from a given vertix
    while (x = getline(&test, &size, fp) != -1)
    {
        // First token received is vertex
        char* token = strtok(test, " ");
        int vertex = atoi(token);

        int weight;
        int node;

        //printf("\n\nVertex: %d\n", vertex);

        // Now for every given vertex, need to iterate to get pairs of connecting vertex and corresponding weight
        while (token != NULL)
        {
            // Get vertex token
            token = strtok(NULL, " ");

            // Just check for if token is NULL
            if (token == NULL)
            {
                break;
            }

            node = atoi(token);

            // Get weight token
            token = strtok(NULL, " ");

            // Just check for if token is NULL
            if (token == NULL)
            {
                break;
            }

            weight = atoi(token);

            //printf("Node: %d Weight: %d\n", node, weight);

            // Inserting to graph
            g->graph[vertex] = insert(g->graph[vertex], node, weight);
        }
    }

    return g;
}

void display(Graph* g)
{
    // Temp to traverse through each list
    Node* temp;

    printf("Length: %d\n", g->n);

    for (int i = 1; i < g->n; i ++)
    {
        printf("\nHead: %d ", i);

        temp = g->graph[i].head;

        if (temp == NULL)
        {
            printf("No outgoing connections");
        }
        else
        {
            while (temp != NULL)
            {
                printf("Vertex: %d Weight: %d ", temp->id, temp->weight);
                temp = temp->next;
            }
        }
    }
    printf("\n");
}

Heap* create_heap(int size)
{
    // Create heap
    Heap* h = (Heap* )malloc(sizeof(Heap));

    // Assign size
    h->n = size - 1;

    // Allocate memory for array
    h->heap = malloc((h->n + 1) * sizeof(Node));

    // As all distances are infinity, order does not matter in heap

    for (int i = 0; i < h->n; i ++)
    {
        // Assigning the id
        h->heap[i].id = i + 1;
        // Assigning the distance
        h->heap[i].dist = INT_MAX;
        // Assigning the previous vertex in the path
        h->heap[i].prev = 0;
    }

    // Test to check whether have been assigned
    /*for (int i = 0; i < h->n; i ++)
    {
        printf("Vertex ID: %d\n", h->heap[i].id);
    }*/

    return h;
}