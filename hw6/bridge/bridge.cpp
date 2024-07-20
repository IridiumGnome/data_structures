#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> graph(1e5); // size of the vector is 10^5

int timer = 0; // count циклы
vector <bool> used(1e5, false); // visited vertex, initially we have not visited any of them
vector <int> tin(1e5, 0),  fup(1e5, 0); // время входа и цикл

void dfs(int u, int p = -1) // for the first vertex in the search parent is -1 (kinda like root, make the first vertex a root)
{
    used[u] = true;  // so we visited this vertex
    tin[u] = fup[u] = timer++;  //
    for (int i = 0; i < (int)(graph[u].size()); i++)
    {
        int to = graph[u][i]; // the child vertex
        if (to == p) continue; // if we get in the parent vertex just continue
        if (used[to])
        {
            fup[u] = min(fup[u], tin[to]); // если мы попали в цикл
        }
        else
        {
            dfs(to, u); //
            fup[u] = min(fup[u], fup[to]); // ищем цикл
            if (fup[to] > tin[u]) // according to the rules if the время захода в вершину меньше чем
            {
                cout << u << " " << to << "\n";
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int numV, numE;
    cin >> numV;
    cin >> numE;
    for (int i = 0; i < numE; i++)
    { // initialize the vector
        int a, b;
        cin >> a;
        cin >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << "\n";

    for (int i = 0; i < numV; i++)
    { // call dfs and i is the vertex we have not visited
        if (!used[i])
        {
            dfs(i);
        }
    }
}
