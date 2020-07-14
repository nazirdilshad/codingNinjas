/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
*/

//code
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
vector<int> path;
bool getpathhelper(int **edges, int v, int a, int b, bool *visited)
{
    map<int, int> mp;
    queue<int> q;
    q.push(a);
    visited[a] = true;
    bool flag = true;
    while (!q.empty() && flag)
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < v; i++)
        {
            if (edges[node][i] && !visited[i])
            {
                mp[i] = node;
                visited[i] = true;
                q.push(i);
                if (i == b)
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    int node = b;
    if (visited[b] == 0)
    {
        return false;
    }
    path.push_back(b);
    while (node != a)
    {
        path.push_back(mp[node]);
        node = mp[node];
    }
    return true;
}

int main()
{
    int V, E;
    cin >> V >> E;
    int **edges = new int *[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            edges[i][j] = 0;
        }
    }
    int first, second;
    for (int i = 0; i < E; i++)
    {
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    cin >> first >> second;
    bool visited[V + 1];
    memset(visited, false, sizeof visited);

    bool flag = getpathhelper(edges, V, first, second, visited);
    if (flag == true)
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }

   

    return 0;
}
