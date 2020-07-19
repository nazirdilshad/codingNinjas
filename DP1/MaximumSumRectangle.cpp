/*
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

//code
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v420;

#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define maxi 100000
#define pii pair<int, int>
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define mem(x, y) memset(x, y, sizeof(x))
#define DANGER                        \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int kadane(int b[], int n)
{
    int max_kadane = b[0], curr_max = b[0];
    for (int i = 1; i < n; i++)
    {
        curr_max = max(b[i], curr_max + b[i]);
        max_kadane = max(max_kadane, curr_max);
    }
    return max_kadane;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int b[n];
    int l = 0, r = 0, max_sum = INT_MIN, top = 0, down = 0;
    for (int i = l; i < m; i++)
    {
        mem(b, 0);

        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                
                b[k] += a[k][j];
                
            }
            //cout << "\n";

            int kadane_max = kadane(b, n);
            //cout << kadane_max << " ";
            if (kadane_max > max_sum)
            {
                max_sum = kadane_max;
            }
        }
    }
    cout << max_sum;
}