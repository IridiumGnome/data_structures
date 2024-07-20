#include <iostream>
#include <vector>

using namespace std;

vector <int> p(101, -1), h(101, 0);
// 'p' to store nodes, 'h' to store heights
// for node p[i] we store a parent of i
// 'h' is the height of a tree with root i
void heightUnion(int a, int b)
{
    if (h[a] > h[b]) // compare heights of trees
    {
        //h[a] = max(h[a], 1 + h[b]); // choose between two heights the maximum one
        p[b] = a; // for node 'b' 'a' is a parent
    }
    else
    {
        //h[b] = max(h[b], 1 + h[a]);
        p[a] = b; // 'b' is parent of 'a'
    }
}

int find_vert(int from, int &local_ans) // to find a root
{
    int i;
    for (i = from; p[i] != -1; i = p[i]) // while we dont reach a root
        local_ans++; // count the # of steps
    return i;
}

void collapsingFind()
{
    int a, root, local_ans = 0;
    cin >> a; // number to find
    root = find_vert(a, local_ans); // get a root for node 'a'
    if (p[a] == root) // if the parent of 'a' is root then the answer is 1 and we dont have to make any changes
        cout << 1 << '\n';
    else
    {
        for (int i = a; p[i] != -1; i = p[i])
        {
            p[i] = root; // root is parent of 'i' now
            local_ans++; // + reset link
        }
        cout << local_ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); // block printing after cin

    int numT, numN;
    cin >> numT;

    for (int j = 0; j < numT; j++)
    {
        cin >> numN;
        for (int i = 0; i < numN; i++) {
            int a, b;
            cin >> a >> b;
            if (b < 0) h[a] = -b; // change the height
            else p[a] = b; // for node "a" there is a parent "b"
        }
    }

    string input;

    while (true)
    {
        cin >> input;
        if (input == "STOP") return 0;
        else if (input[0] == 'U')
        {
            int a, b;
            cin >> a >> b;
            heightUnion(a, b);
        }
        else if (input[0] == 'F') collapsingFind();
    }
}
