/*
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2
*/

//code
#include <bits/stdc++.h>
using namespace std;
vector<int> edges[1000006];
int visited[100006];


void solve()
{
    int v, e;
    cin >> v >> e;
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    
    int level[v + 1];
    memset(level, 0, sizeof level);
    queue<int> q;
    q.push(0);
    int x = 0;
    level[0] = x;
    visited[0] = 1;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        //x++;
        for (int i = 0; i < edges[element].size(); i++)
        {
            int adjacent = edges[element][i];

            if (!visited[adjacent])
            {
                q.push(adjacent);
                visited[adjacent] = 1;
                level[adjacent] = level[element] + 1;
                if (adjacent == v - 1)
                {
                    break;
                }
            }
        }
    }

    cout << level[v - 1] << endl;
    
    for (int i = 0; i < 1000006; i++)
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
