/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/

//code
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getminvertex(int* weight,bool* visited,int v){
    
    int minvertex = -1;
    int ll = 100002;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && weight[i] < ll)
        {
            minvertex = i;
            ll = weight[i];
        }
    }
    return minvertex;
}

void prims(int** edges, int v){
    bool* visited = new bool[v]();
    int* weight = new int[v];
    int* parent =  new int[v];
    for(int i = 0 ;i<v;i++){
        weight[i] = 100001;
        //parent[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;
    for(int i=0 ;i<v-1;i++){
        int minvertex = getminvertex(weight,visited,v);
        visited[minvertex] = true;
        
        for(int j = 0; j < v; j++){
            if(edges[minvertex][j] != 0 && !visited[j]){
                if(weight[j]> edges[minvertex][j]){
                    weight[j] = edges[minvertex][j];
                    parent[j] = minvertex;
                }
            }
        }
    }
    for(int i=1 ;i<v;i++){
        if(parent[i] < i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
    //return;
    
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    int** edges = new int*[V];
    for(int i = 0;i<V;i++){
        edges[i] = new int[V];
        for(int j= 0;j<V;j++){
            edges[i][j] = 0;
        }
        
    }
    for(int i = 0; i < E ; i++){
        int s,e,w;
        cin>>s>>e>>w;
        edges[s][e] = w;
        edges[e][s] = w;
    }
    prims(edges,V);

  return 0;
}
