/*
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1
*/

//code
#include <bits/stdc++.h>
using namespace std;
vector<int> edges[100000];
vector<int> visited;
void dfs(int start, vector<int> &finishstack)
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
    finishstack.push_back(start);
}
void dfs2(int start)
{
    visited[start] = 1;
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjacent = edges[start][i];
        if (visited[adjacent] == 0)
        {
            dfs2(adjacent);
        }
    }
}

void solve()
{
    int v, e;
    cin >> v >> e;
    visited.resize(v + 1, 0);
    for (int i = 0; i < e; i++)
    {
        int j, k;
        cin >> j >> k;
        edges[j].push_back(k);
    }

    vector<int> finishedvertices;
    for (int i = 0; i < v + 1; i++)
    {
        visited[i] = 0;
    }
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            dfs(i, finishedvertices);
        }
    }

    for (int i = 0; i < v + 1; i++)
    {
        visited[i] = 0;
    }

    int cnt = 0;
    while (finishedvertices.size() != 0)
    {
        int element = finishedvertices.back();
        finishedvertices.pop_back();
        if (visited[element] != 0)
        {
            continue;
        }
        cnt++;
        dfs2(element);
    }
    cout << cnt << endl;

    for (int i = 0; i < 100000; i++)
    {
        edges[i].clear();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}