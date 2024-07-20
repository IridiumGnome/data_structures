In this program, I used the adjacency list (vector of vectors "graph") and DFS.
There are also vectors "used" (to check visited vertex, initially all variables are false), 
"tin" (entry time), "fup" (minimum of tin);
"timer" is a counter;

First, fill the vector "graph" with vertex. After call function "dfs" for each connected component 
of the graph.

Inside "dfs" function:
The first vertex I check came from -1 (something like parent). For each vertex I also check recursively
its children (go down the graph checking each vertex) and if I get into the loop 
fup[u] = min(fup[u], tin[to]) and there is no bridge. Otherwise fup[u] = min(fup[u], fup[to]);

According to the rule current edge (u,to) in the DFS tree is a bridge iff fup[to]>tin[u]. 
If it's so print out the bridge.

The time complexity is O(V+E) where V is the # of vertices and E is the # of edges.
Because I used DFS and complexity of DFS is O(V+E) only if the graph is represented as an adjacency list.
While traversal each node is processed and all the edges that connect to the neighboring node. 
In the directed graph each edge is processed once, but in the undirected graph, each edge is processed 
twice.