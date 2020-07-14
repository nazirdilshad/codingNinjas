/*
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output
1 3
2
*/

//code
#include <bits/stdc++.h>
using namespace std;
vector<int> edges[10000];
vector<int> edgesT[10000];
int visited[20001];
vector<int> component;

void dfs(int start, stack<int> &finishstack)
{
    visited[start] = 1;
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjacent = edges[start][i];
        if (visited[adjacent] == 0)
        {
            dfs(adjacent, finishstack);
        }
    }
    finishstack.push(start);
}

void dfs2(int start, int counting)
{
    visited[start] = 1;
    component[start] = counting;
    for (int i = 0; i < edgesT[start].size(); i++)
    {
        int adjacent = edgesT[start][i];
        if (visited[adjacent] == 0)
        {
            dfs2(adjacent, counting);
        }
    }
}

void solve()
{
    while (1)
    {
        int v, e;
        cin >> v;
        if (v == 0)
        {
            return;
        }
        cin >> e;
        component.resize(v + 1);
        int sol[v + 1];
        memset(sol, 1, sizeof sol);

        memset(visited, 0, sizeof visited);
        for (int i = 0; i < e; i++)
        {
            int j, k;
            cin >> j >> k;
            edges[j].push_back(k);
            edgesT[k].push_back(j);
        }
        stack<int> finishedvertices;
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {

                dfs(i, finishedvertices);
            }
        }
        memset(visited, 0, sizeof visited);

        int counting = 0;
        while (finishedvertices.size() != 0)
        {
            int element = finishedvertices.top();
            finishedvertices.pop();
            if (visited[element] != 0)
            {
                continue;
            }

            counting++;
            sol[counting - 1] = 1;
            dfs2(element, counting);
        }

        for (int i = 1; i < v + 1; i++)
        {
            for (int j = 0; j < edges[i].size(); j++)
            {

                if (component[i] != component[edges[i][j]])
                {

                    sol[component[i]] = 0;
                    break;
                }
            }
        }

            for (int i = 1; i < v + 1; i++)
        {
            if (sol[component[i]] != 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;

        for (int i = 0; i < 10000; i++)
        {
            edges[i].clear();
            edgesT[i].clear();
        }
        component.clear();
    }
}

int main()
{
    solve();
}
