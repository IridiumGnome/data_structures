To check if the graph is bipartite I use DFS and vertex coloring algorithm.
There are two vectors graph (to store graph as an adjacency list) and paint (to store colored vertices).

The algorithm:
If the vertex is unvisited yet it's color is 0. Start coloring from the random vertex and paint it a 
random color. Go through all edges and paint vertex inverse colors. If while checking two adjacent edges
found out that they are the same color then the graph is not bipartite. Terminate the program. Otherwise, 
if the process succeeds the graph is bipartite and print out 2 sets. Set 1 consists of variables of 
paint with a value of 1, set 2 consists of variables of paint with value 2.  

The time complexity is O(V+E) where V is the # of vertices and E is the # of edges.
Because I used DFS and complexity of DFS is O(V+E) only if the graph is represented as an adjacency list.
While traversal each node is processed and all the edges that connect to the neighboring node. 
In the directed graph each edge is processed once, but in the undirected graph, each edge is processed 
twice.