/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

//code

#include <iostream>
#include <bits/stdc++.h>
#define pb push_back

using namespace std;
int edges[5000][5000] = {0};
bool visited[1001];

void dfs(int si, int n, vector<int> &v)
{
    visited[si] = true;
    v.pb(si);
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        if (edges[si][i] && !visited[i])
        {
            dfs(i, n, v);
        }
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    int a, b;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    vector<int> v;
    memset(visited, false, sizeof visited);
    dfs(0, V, v);
    if (v.size() < V)
    {
        cout << "false";
    }
    else
    {
        cout << "true";
    }

    return 0;
}