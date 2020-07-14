/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 
*/

//code
#include<bits/stdc++.h>
void dfs(int edges[][5000],int si,int n,int visited[]){
    visited[si]=1;
    for(int i=1;i<=n;i++){
        if(visited[i]){
            continue;
        }
        if(edges[si][i] && visited[i]==0){
            dfs(edges,i,n,visited);
                
        }
    }
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int edges[5500][5000];
    memset(edges,0,sizeof edges);
    int visited[1000];
    memset(visited,0,sizeof visited);
    int cnt = 0;
    
	for(int i=0;i<m;i++){
        edges[u[i]][v[i]]=1;
        edges[v[i]][u[i]]=1;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<edges[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            cnt = cnt + 1;
            
            dfs(edges,i,n,visited);
        }
    }
    return cnt;
}