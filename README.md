# Dijkstra-in-C
 
Dijkstra is used to solve a **Single-Destination Shortest Path** problem to get the shortest path from all vertices in a graph to a given vertex.


## Input Format

The first line of the input file contains the number of vertices in the graph. <br>
The subsequent lines consist of: {Node} {vertex, weight of connection to vertex} where the pair of {vertex, weight} can be repeated for every other vertex in the graph. <br>
The last vertex (the highest numbered vertex) is taken as the Destination.


## Output Format

Each line of the output corresponds to: {Node} {Vertices in the path (including Node and Destination)} {Path Length} <br>
In case there is no path, "NO PATH" is printed

## How to Use

Clone this repository and run using the following command: `make -f makefile.mk`<br>
Input file can be changed in **line 57 in server.c** <br>

> fp = fopen("file_name.txt", "r");<br>

**Note:** To use the `make` command in windows, use Windows Subsystem for Linux


