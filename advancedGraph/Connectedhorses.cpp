/*
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2
*/

//code
#include <bits/stdc++.h>
using namespace std;
int n, m;
long long cnt, mod = 1e9 + 7;
int visited[1050][1050];
int graph[1060][1060];
long long fact[100000];

void factorial()
{

    fact[0] = 1;
    for (long int i = 1; i <= 100000; i++)
    {
        fact[i] = ((fact[i - 1]* i )% mod) % mod;
    }
}

void connectingDFS(int graph[][1060], int u, int v)
{
    int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    cnt++;
    visited[u][v] = 1;
    for (int i = 0; i < 8; i++)
    {
        int x = u + X[i];
        int y = v + Y[i];

        if (x <= 0 || y <= 0 || x > n || y > m)
        {
            continue;
        }
        if (visited[x][y] == 0 && graph[x][y] == 1)
        {
            connectingDFS(graph, x, y);
        }
    }
}
void solve()
{
    int q;
    cin >> n >> m >> q;

    memset(graph, 0, sizeof graph);
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
    }
    vector<long long> ans;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (graph[i][j] == 1 && !visited[i][j])
            {
                cnt = 0;
                connectingDFS(graph, i, j);
                ans.push_back(fact[cnt]);
            }
        }
    }
    long long answer = ans[0] % mod;
    for (int i = 1; i < ans.size(); i++)
    {
        //cout<<ans[i]<<" ";
        answer = (answer % mod * ans[i] % mod) % mod;
    } 
    cout << answer << endl;
}
int main()
{
    int t;
    cin >> t;
    factorial();
    while (t--)
    {
        solve();
    }
    return 0;
}
