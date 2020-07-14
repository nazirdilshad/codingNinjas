/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). 
Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
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

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool dfs(int** edges,int start,int v,bool* visited,int target,vector<int> &vec){
    if(visited[start]){
        return false;
    }
    visited[start]=true;
    if(start == target){
        vec.push_back(start);
        return true;
    }
    //visited[start] =true;
    //vec.push_back(start);
    
    for(int i= 0;i<v;i++){
        if(edges[start][i]){
            bool x = dfs(edges,i,v,visited,target,vec);
                if(x==true){
                    vec.push_back(start);
                    return true;
                }
            }
    }
    return false;
        
    
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    
    int a,b;
    for(int j=0;j<E;j++){
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1; 
        }
    cin>>a>>b;
    
    bool* visited = new bool[V];
    
    for(int j=0;j<V;j++){
        visited[j]=false;
    }
    vector<int>vec;
    
    dfs(edges,a,V,visited,b,vec);
    if(visited[b]){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
    }
    

  return 0;
}

