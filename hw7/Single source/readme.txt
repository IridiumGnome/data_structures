In this program, I have 3 vectors "graph" (vector of vectors to store graph as an adjacency list),
"dist" and "parent" (to store distances and predecessors respectively), "visited" (to check
if I visited the vertex or not), "path" (to print out the path between vertices).

To find the shortest path I used Dijkstra's algorithm.

Initially dist[starting point] = 0 and dist[others] = INF (1000000), visited[all] = false (have not
visited yet). Each time I check all vertices that are adjacent with current vertex to update
for better distance (looking for smallest weight). If there is no way to get in some vertices
distance for them is INF and algorithm stops. After each relaxation values of "dist" and "parent" are 
updated.

After performing all the iterations "dist" stores the lengths of the shortest paths to all 
vertices, and "parent" stores the predecessors of all vertices (except starting vertex).

After that, I print out the results.
First, check if the distance between vertices is not INF (otherwise there is no path and print out 
"Impossible"). Then restore the path using "parent" and pushing all values into the vector "path". 
Reverse vector. In the end, printing out the whole path from V0 to all remaining vertices and the weights. 