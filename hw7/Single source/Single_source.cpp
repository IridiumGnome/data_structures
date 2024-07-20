#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1000000;

using namespace std;

typedef pair <int, int> Pair;

vector <vector<Pair>> graph;

int main()
{
    int numV, numE;
    int x, y, w;

    while(cin >> numV)
    {
         cin >> numE;

        graph.resize(numV);

        // initialize graph
        for(int i = 0; i < numE; i++)
        {
            cin >> x;
            cin >> y;
            cin >> w;

            graph[x].push_back(make_pair(y, w));
        }

        int s = 0; // starting point

        vector <int> dist(numV, INF), parent(numV);

        dist[s] = 0; // distance for the starting point is 0

        vector <bool> visited(numV, false); // check if we visited or not

        // Dijkstra's algorithm
        for (int i=0; i<numV; ++i) {
            int v = -1;
            for (int j=0; j<numV; ++j)
                // релаксация
                if (!visited[j] && (v == -1 || dist[j] < dist[v]))
                    v = j;
            if (dist[v] == INF)
                break;
            visited[v] = true;

            for (int j=0; j<graph[v].size(); ++j) {
                int to = graph[v][j].first;
                int	weight = graph[v][j].second;
                if (dist[v] + weight < dist[to]) {
                    dist[to] = dist[v] + weight;
                    parent[to] = v;
                }
            }
        }

        vector<int> path; // to store path

        //cout << "\n";

        for(int j = 01; j < numV; j++){
            if(dist[j]!=INF){ // check if there is a path
                for (int v=j; v!=s; v=parent[v])
                    path.push_back (v);
                path.push_back (s);
                reverse(path.begin(), path.end());
                for (int value : path){
                    cout << value << " ";
                }
                cout << dist[j] << "\n";
            }
            else
                cout << "Impossible\n";
            //cout << "\n";
            path.clear();
        }
        cout << "\n";
    }
}
