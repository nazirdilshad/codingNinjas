/*
You are given a connected weighted undirected graph without any loops and multiple edges.

Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, a graph's minimum spanning tree is not unique.

Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or included at least in one MST, or not included in any MST.
Input
The first line contains two integers n and m (2 ≤ n ≤ 10^5, ) — the number of the graph's vertexes and edges, correspondingly. Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi" (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 10^6, ai ≠ bi), where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight. It is guaranteed that the graph is connected and doesn't contain loops or multiple edges.
Output
Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which the edges are specified in the input.
Sample input 1
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
sample output 1
none
any
at least one
at least one
any
Sample input 2
3 3
1 2 1
2 3 1
1 3 2
sample output 2
any
any
none
sample input 3
3 3
1 2 1
2 3 1
1 3 1
sample output 3
at least one
at least one
at least one
Note
In the second sample the MST is unique for the given graph: it contains two first edges.

In the third sample any two edges form the MST for the given graph. That means that each edge is included at least in one MST.
*/

//code
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
 
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
 
using namespace std;
 
struct edge
{
    int from, to, cost, index;
 
    edge(int x,int y,int z,int i)
    {
        from = x, to = y, cost = z, index = i;
    }
 
    bool operator < (const edge &e) const
    {
        return e.cost > cost;
    }
};
 
struct disjointset
{
    vector<int> rank, parent;
    int subtrees;
 
    disjointset(int n)
    {
        subtrees = n;
        for(int i=0;i<n;i++)
            rank.pb(1),parent.pb(i);
    }
 
    int find_set(int x)
    {
        if(x == parent[x])
            return x;
        return parent[x] = find_set(parent[x]);
    }
 
    void link(int x,int y)
    {
        if(rank[x] > rank[y])
            swap(x, y);
        parent[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
    }
 
    bool union_sets(int x,int y)
    {
        x = find_set(x),y = find_set(y);
        if(x != y)
        {
            link(x,y);
            subtrees--;
        }
        return x != y;
    }
 
    bool same_set(int x,int y)
    {
        return find_set(x) == find_set(y);
    }
};
 
vector<edge> edges;
int sol[100005];
vector<vector<pair<int, int> > > graph(100005);
map<pair<int,int>, int > tbd;
int visited[100005];
 
int dfs(int node,int depth,int parent)
{
    visited[node] = depth;
    int maxi = depth;
    for(int i=0;i<graph[node].size();i++)
    {
        int next = graph[node][i].first;
        int k = graph[node][i].second;
        if(!visited[next])
        {
            int temp = dfs(next, depth + 1, node);
            maxi = min(maxi, temp);
            if(temp > depth)
                sol[k] = 0;
        }
        else if(parent != next) maxi = min(maxi, visited[next]);
    }
    return maxi;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, x, y, z;
    cin >> n >> m;
    disjointset dset(n + 1);
    for(int i=0;i<m;i++)
    {
        cin >> x >> y >> z;
        edges.push_back(edge(x, y, z, i));
    }
    sort(edges.begin(), edges.end());
    for(int i=0;i<m;i++)
    {
        int k = i;
        tbd.clear();
        while(1)
        {
            edge temp = edges[k];
            if(dset.same_set(temp.from, temp.to))
                sol[temp.index] = 2;
            else
            {
                int x = dset.find_set(temp.to), y = dset.find_set(temp.from);
                tbd[mp(x,y)]++;
                tbd[mp(y,x)]++;
                graph[x].clear();
                graph[y].clear();
                visited[x] = 0;
                visited[y] = 0;
            }
            if(k < m - 1 && edges[k + 1].cost == temp.cost)
                k++;
            else break;
        }
        for(int j=i;j<=k;j++)
        {
            edge temp = edges[j];
            if(sol[temp.index] == 2) continue;
            sol[temp.index] = 1;
            int x = dset.find_set(temp.to), y = dset.find_set(temp.from);
            graph[x].pb(mp(y, temp.index));
            graph[y].pb(mp(x, temp.index));
        }
        for(int j=i;j<=k;j++)
        {
            edge temp = edges[j];
            if(sol[temp.index] == 2) continue;
            int x = dset.find_set(temp.to);
            if(!visited[x])
                dfs(x, 1, x);
        }
        for(int j=i;j<=k;j++)
        {
            edge temp = edges[j];
            if(sol[temp.index] == 2) continue;
            int x = dset.find_set(temp.to), y = dset.find_set(temp.from);
            if(tbd[mp(x,y)] > 1)
                sol[temp.index] = 1;
        }
        for(int j=i;j<=k;j++)
        {
            edge temp = edges[j];
            dset.union_sets(temp.from, temp.to);
        }
        i = k;
    }
    for(int i=0;i<m;i++)
    {
        if(sol[i] == 0) cout << "any";
        else if(sol[i] == 1) cout << "at least one";
        else cout << "none";
        cout << "\n";
    }
    return 0;
}