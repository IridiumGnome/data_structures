#include <iostream>
#include <vector>

using namespace std;

int INF = 1000;
int N = 100;

int path[11][11]; // to restore path in future
int graph[11][11]; // to store graph as an adjacency matrix

void show_path( int u, int v)
{
    if(path[u][v] == N) // if there is no path just break
        return;

    int x = u;

    cout << x << " ";
    while ( x != v ){
         x = path[x][v];
        cout << x  << " "; // print out the path
    }
    cout << graph[u][v] << "\n"; // print out the weight
}

int main()
{
    int numE, numV;

    while(cin >> numV)
    {
        cin >> numE;

        // fill matrix with 0 and path with 100
        for(int i = 0; i < numV; i++)
        {
            for(int j = 0; j < numV; j++)
            {
                graph[i][j] = 0;
                path[i][j] = N;
            }
        }

        // initialize graph as an adjacency matrix
        for(int i = 0; i < numE; i++)
        {
            int x, y, w;

            cin >> x;
            cin >> y;
            cin >> w;

            graph[x][y] = w;
            path[x][y] = y; // store path
        }


        // if there is no path between two vertex then the distance is INF
        for (int i = 0; i < numV; i++){
            for (int j = 0; j < numV; j++){
                if (graph[i][j] == 0 && i != j){
                    graph[i][j] = INF;
                }
            }
        }

        // Floyd Warshall algorithm
        for (int k=0; k<numV; k++){
            for (int i=0; i<numV; i++){
                if(graph[i][k] != INF){
                    for (int j=0; j<numV; j++) {
                    // if the path from i to k and from k to j is better than the path from i to j
                    // change to better solution
                        if(graph[i][j] > graph[i][k] + graph[k][j]){
                            graph[i][j] = graph[i][k] + graph[k][j];
                            path[i][j] = path[i][k];
                        }

                    }
                }
            }
        }

        // call function to print out the path between vertices
        for(int i = 0; i < numV; i++)
            for(int j = 0; j < numV; j++){
                show_path(i, j);
            }
        cout << "\n";
    }

}
