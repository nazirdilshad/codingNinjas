/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5
*/

//code
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct edges{
    int s,e,w;
};

bool compare(edges i1,edges i2){
    return i1.w < i2.w;
}

int getparent(int s,int* parent){
    if(parent[s]==s){
        return s;
    }
    return getparent(parent[s],parent);
}


edges* kruskal(edges* input,int v,int e){
    edges* output = new edges[v-1];
    int count = 0;
    int* parent = new int[v];
    for(int i = 0;i < v; i++){
        parent[i] = i;
    }
    int i= 0;
    while(count<v-1){
        edges currentedge = input[i];
        int sparent = getparent(currentedge.s,parent);
        int dparent = getparent(currentedge.e,parent);
        
        if(sparent != dparent){
            output[count] = currentedge;
            count++;
            parent[sparent] = dparent;
        }
        i+=1;
    }
    return output;
}


int main()
{
     int V, E, tempX, tempY;
     cin >> V >> E;
    edges* input = new edges[E];
    int a, b,c;
    for(int i = 0; i < E; i++){
        cin>>a>>b>>c;
        input[i].s = a;
        input[i].e = b;
        input[i].w = c;
    }
    
    sort(input,input+E,compare);
    
     edges* output = kruskal(input,V,E);
    for(int i = 0; i < V-1; i++){
        if(output[i].s < output[i].e){
            cout<<output[i].s<<" "<<output[i].e<<" "<<output[i].w<<endl;
        }
        else{
            cout<<output[i].e<<" "<<output[i].s<<" "<<output[i].w<<endl;
        }
    }

  
  return 0;
}
