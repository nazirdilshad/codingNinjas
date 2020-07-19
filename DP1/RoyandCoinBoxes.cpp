/*
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/

//code
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m, l, r, q, x;
    cin >> n >> m;
    ll everycoin[n+1] = {0};
    ll start[n + 1], end[n + 1], coinineachbox[n + 1];
    //start[n + 1] = {0};
    //end[n + 1] = {0};
    ll b[n + 1];
    memset(b, 0, sizeof(b));
    memset(coinineachbox, 0, sizeof(coinineachbox));
    memset(start, 0, sizeof(start));
    memset(end, 0, sizeof(end));
    for (ll i = 0; i < m; i++)
    {
        cin >> l >> r;
        start[l] += 1;
        end[r] += 1;
    }
    coinineachbox[1] = start[1];
    for (int i = 2; i <= n; i++)
    {
        coinineachbox[i] = coinineachbox[i - 1] + start[i] - end[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        //cout << coinineachbox[i] << " ";
        everycoin[coinineachbox[i]]++;
    }
    b[n] = everycoin[n];
    for (int i = n - 1; i >= 1; i--)
    {
        b[i] = everycoin[i] + b[i + 1];
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << b[i] << " ";
    // }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        cout << b[x] << endl;
    }

    return 0;
}
