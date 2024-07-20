In this program, I used 2d arrays to store graph as an adjacency matrix and to store path.

First I fill both arrays with some values (0 and 100). Then start initializing graph 
as an adjacency matrix and setting path between vertices. After that I used Floyd-Warshall 
Algorithm to find the shortest path.

If there is no path between two vertexes then the distance is INF (1000)
There are 3 vertices and if the path from I to k and from k to j is better than the path 
from I to j update "graph" and "path" values (arrays that are used).

After that, I call the function "show_path" to print out the path.

Inside this function, I check if the path between vertices exists. Is so print out the path 
and weight.