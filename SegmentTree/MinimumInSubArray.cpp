/*Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
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

void buildtree(int a[], int tree[], int start, int end, int treenode)
{
    if (start == end)
    {
        tree[treenode] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    buildtree(a, tree, start, mid, 2 * treenode);
    buildtree(a, tree, mid + 1, end, 2 * treenode + 1);
    tree[treenode] = min(tree[treenode * 2], tree[2 * treenode + 1]);
}

void updateTree(int a[], int tree[], int start, int end, int treenode, int idx, int value)
{
    if (start == end)
    {
        a[idx] = value;
        tree[treenode] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (idx > mid)
    {
        updateTree(a, tree, mid + 1, end, 2 * treenode + 1, idx, value);
    }
    else
    {
        updateTree(a, tree, start, mid, 2 * treenode, idx, value);
    }
    tree[treenode] = min(tree[2 * treenode], tree[2 * treenode + 1]);
}

int query(int tree[], int start, int end, int treenode, int left, int right)
{

    //completely outside
    if (start > right || end < left)
    {
        return 100000;
    }
    //completely inside
    if (start >= left && end <= right)
    {
        return tree[treenode];
    }

    int mid = (start + end) / 2;
    int ans = query(tree, start, mid, 2 * treenode, left, right);
    int ans2 = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
    return min(ans, ans2);
}

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n], tree[4 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    char c;
    int l, r;
    buildtree(a, tree, 0, n - 1, 1);

    for (int i = 1; i < 2 * n; i++)
    {
        //cout << tree[i] << " ";
    }
    for (int i = 0; i < q; i++)
    {
        cin >> c >> l >> r;
        if (c == 'q')
        {
            cout << query(tree, 0, n - 1, 1, l - 1, r - 1) << endl;
        }
        if (c == 'u')
        {
            updateTree(a, tree, 0, n - 1, 1, l - 1, r);
        }
    }
}