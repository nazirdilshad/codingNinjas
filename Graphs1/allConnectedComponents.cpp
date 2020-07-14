/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/

//code
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int edges[5000][5000];
bool visited[1001];

void dfs(int si, int n, vector<int> *vec)
{
    visited[si] = true;
    vec->pb(si);
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        if (edges[si][i] && !visited[i])
        {
            dfs(i, n, vec);
        }
    }
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int a, b;
    memset(edges, 0, sizeof edges);
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    memset(visited, false, sizeof visited);

    for (int i = 0; i < V; i++)
    {

        if (!visited[i])
        {
            vector<int> v;
            dfs(i, V, &v);
            sort(v.begin(), v.end());
            for (auto i : v)
            {
                cout << i << " ";
            }
            v.clear();
            cout << endl;
        }
    }

    return 0;
}
