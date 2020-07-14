/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

//code
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int getminvertex(int *distance, bool *visited, int v)
{
    int minvertex = -1;
    int ll = 100002;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && distance[i] < ll)
        {
            minvertex = i;
            ll = distance[i];
        }
    }
    return minvertex;
}

void djikstra(int **edges, int v)
{
    int *dist = new int[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = 100001;
    }
    bool *visited = new bool[v]();
    dist[0] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        int minvertex = getminvertex(dist, visited, v);
        visited[minvertex] = 1;
        //cout << minvertex << "\n";
        for (int j = 0; j < v; j++)
        {
            if (!visited[j] && edges[minvertex][j])
            {
                dist[j] = min(dist[j], (dist[minvertex] + edges[minvertex][j]));
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

int main()
{
    int V, E, tempX, tempY;
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

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a][b] = c;
        edges[b][a] = c;
    }
    djikstra(edges, V);

    return 0;
}
