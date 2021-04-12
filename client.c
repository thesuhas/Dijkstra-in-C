#include "server.h"

int main(void)
{
    // Create Graph
    Graph* g = file();

    display(g);

    // Create Heap
    Heap* h = create_heap(g->n);

    g = Dijkstra(g, h);

    // Test
    for (int i = 1; i < g->n; i ++)
    {
        printf("Node: %d Prev: %d\n", i, g->graph[i].prev);
    }

    get_paths(g);
}