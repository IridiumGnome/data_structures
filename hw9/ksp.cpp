#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n, s = 1, f, m, k;

vector <vector <pair <int, int> > > graph(1e5);

struct deleted_edge{ // removed edge
    int a, b;
};

int Dijkstra(deleted_edge x, vector <int> &p) // p changes in main function also
{
    vector <int> d(1e5, 100000000); // dist from s to d[i]
    d[s] = 0;
    set <pair <int, int> > q; // most min
    q.insert({0, s}); // (dist, vertex)

    while (!q.empty())
    {
        int v = q.begin()->second; // -> vertex
        q.erase(q.begin());

        for (int i = 0; i < graph[v].size(); i++) // check all vertices we can go from V (current)
        {
            int to = graph[v][i].first, w = graph[v][i].second;
            if ((to == x.a && v == x.b) || (to == x.b && v == x.a)) // check if deleted edge or not
            {
                q.erase({d[to], to}); // remove from set
            }
            else if (d[to] > d[v] + w)
            {
                q.erase({d[to], to});
                d[to] = d[v] + w;
                p[to] = v;
                q.insert({d[to], to}); // insert pair
            }
        }
    }
    if (d[f] == 100000000)
    {
        return -1; // no path
    }
    return d[f]; // otherwise return dist
}

void print_path(vector <int> p)
{
    reverse(p.begin(), p.end());
    for (int i : p) cout << i << ' ';
    cout << endl;
}

int main()
{
    cin >> n >> m;
    f = n;

    // initialize network
    for (int i = 0, a, b, x; i < m; i++)
    {
        cin >> a >> b >> x;
        graph[a].push_back({b, x});
    }

    cin >> k;

    vector <int> p(1e5, -1); // to store parents
    vector <pair <int, vector <int> > > ans; // store answers (dist, vector p (path)) sort according to int
    map <vector <int>, bool> was; // store paths from s to f (to avoid collisions)
    int dist = Dijkstra({-1, -1}, p); // check 1st time when there are all edges

    if (dist != -1)
    {
        vector <int> path;
        for (int i = f; i != 1; i = p[i]) path.push_back(i);
        path.push_back(1);
        ans.push_back({dist, path});
        was[path] = true; // paths exist
    }
    else
    {
        cout << "There is no path";
        return 0;
    }
    // yans
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int to = graph[i][j].first;
            vector <int> p(1e5, -1);
            int dist = Dijkstra({i, to}, p);
            if (dist != -1)
            {
                vector <int> path;
                for (int i = f; i != 1; i = p[i]) path.push_back(i);
                path.push_back(1);
                if (!was[path]) // if there is no path like this
                {
                    ans.push_back({dist, path});
                    was[path] = true;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; i++)
    {
        print_path(ans[i].second);
    }
    return 0;
}
