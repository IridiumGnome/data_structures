#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> graph;
vector <int> paint; // store colored

int invert(int c) {
    return c == 1 ? 2 : 1; // change the color
}

void dfs(int v, int c) {   //c is the color of current vertex
    paint[v] = c;

    for (int u: graph[v]) {
        if (paint[u] == 0) {    // not visited yet
            dfs(u, invert(c));
        } else if (paint[u] == c) {
            cout << "false" << endl;
            exit(0); // terminate program
        }
    }
}

int main()
{
    int numV, numE;
    cin >> numV;
    cin >> numE;

    graph.resize(numV);
    paint.resize(numV);

    for(int i = 0; i < numE; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < graph.size(); i++) {
        if (paint[i] == 0)
            dfs(i, 1);
    }

    cout << "true" << endl;

    // print set 1
    for(int i = 0; i < paint.size(); i++)
    {
        if(paint[i] == 1)
            cout << i << " ";
    }
    cout << "\n";
    //print set 2
    for(int i = 0; i < paint.size(); i++)
    {
        if(paint[i] != 1)
            cout << i << " ";
    }
}
