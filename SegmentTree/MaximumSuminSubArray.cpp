/*Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
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

struct node
{
    ll sum;
    ll msum;
    ll bps; //best prefix sum
    ll bss; //best suffix sum
};
void buildtree(int *a, node *tree, int start, int end, int treenode)
{
    if (start == end)
    {
        tree[treenode].sum = a[start];
        tree[treenode].msum = a[start];
        tree[treenode].bps = a[start];
        tree[treenode].bss = a[start];
        return;
    }
    int mid = (start + end) / 2;
    buildtree(a, tree, start, mid, 2 * treenode);
    buildtree(a, tree, mid + 1, end, 2 * treenode + 1);
    node left = tree[2 * treenode];
    node right = tree[2 * treenode + 1];

    tree[treenode].sum = left.sum + right.sum;
    tree[treenode].bps = max(left.bps, left.sum + right.bps);
    tree[treenode].bss = max(right.bss, right.sum + left.bss);
    ll a1 = left.sum + right.bps;
    ll b = right.sum + left.bss;
    ll c = left.bss + right.bps;
    //ll d = max(left.msum , right.msum);
    tree[treenode].msum = max(left.msum, max(right.msum, max(a1, max(b, c))));

    return;
}

/*void updateTree(int *a, node *tree, int start, int end, int treenode, int idx, int value)
{
    if (start == end)
    {
        a[idx] = value;
        tree[treenode].maximum = value;
        tree[treenode].smaximum = INT_MIN;

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
    node left = tree[2 * treenode];
    node right = tree[2 * treenode + 1];

    tree[treenode].maximum = max(left.maximum, right.maximum);
    tree[treenode].smaximum = min(max(left.maximum, right.smaximum), max(right.maximum, left.smaximum));
}
*/

node query(node *tree, int start, int end, int treenode, int left, int right)
{
    node minni;
    minni.msum = minni.sum = minni.bps = minni.bss = -1000000;
    //completely outside
    if (start > right || end < left)
    {
        return minni;
    }
    //completely inside
    if (start >= left && end <= right)
    {
        return tree[treenode];
    }

    int mid = (start + end) / 2;
    node left1 = query(tree, start, mid, 2 * treenode, left, right);
    node right1 = query(tree, mid + 1, end, 2 * treenode + 1, left, right);

    node fanswer;
    fanswer.sum = left1.sum + right1.sum;
    fanswer.bps = max(left1.bps, left1.sum + right1.bps);
    fanswer.bss = max(right1.bss, right1.sum + left1.bss);
    ll a1 = left1.sum + right1.bps;
    ll b = right1.sum + left1.bss;
    ll c = left1.bss + right1.bps;
    fanswer.msum = max(left1.msum, max(right1.msum, max(a1, max(b, c))));

    return fanswer;
}

int main()
{
    int n, q;
    cin >> n;
    int *a = new int[n];
    node *tree = new node[4 * n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    char c;
    int l, r;
    buildtree(a, tree, 0, n - 1, 1);

    for (int i = 1; i < 2 * n; i++)
    {
        //cout << tree[i].maximum << " ";
    }
    for (int i = 0; i < q; i++)
    {
        // cin >> c >> l >> r;
        // if (c == 'Q')
        // {
        //     cout << query(tree, 0, n - 1, 1, l - 1, r - 1).maximum + query(tree, 0, n - 1, 1, l - 1, r - 1).smaximum << endl;
        // }
        // if (c == 'U')
        // {
        //     updateTree(a, tree, 0, n - 1, 1, l - 1, r);
        // }

        cin >> l >> r;
        cout << query(tree, 0, n - 1, 1, l - 1, r - 1).msum << endl;
    }
}