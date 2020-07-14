/*
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
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
0 1 3 2
*/
//code

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
    int **edges = new int *[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V ; j++)
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
    int visited[V + 1];
    memset(visited, 0, sizeof visited);

    
    for(int i = 0; i < V ; i++) {
        if(!visited[i]) {
             queue<int> q;
    q.push(i);
    visited[i] = 1;
    cout << i << " ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < V; i++)
        {
            if (edges[node][i] && visited[i] == 0)
            {
                cout << i << " ";
                visited[i] = 1;
                q.push(i);
            }
        }
        //cout << q.front() << " ";
    }   
        }
    }

    return 0;
}

