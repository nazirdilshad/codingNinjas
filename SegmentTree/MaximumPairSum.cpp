/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
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
    int maximum;
    int smaximum;
};
void buildtree(int *a, node *tree, int start, int end, int treenode)
{
    if (start == end)
    {
        tree[treenode].maximum = a[start];
        tree[treenode].smaximum = INT_MIN;
        return;
    }
    int mid = (start + end) / 2;
    buildtree(a, tree, start, mid, 2 * treenode);
    buildtree(a, tree, mid + 1, end, 2 * treenode + 1);

    node left = tree[2 * treenode];
    node right = tree[2 * treenode + 1];
    tree[treenode].maximum = max(left.maximum, right.maximum);
    tree[treenode].smaximum = min(max(left.maximum, right.smaximum), max(right.maximum, left.smaximum));
    return;
}

void updateTree(int *a, node *tree, int start, int end, int treenode, int idx, int value)
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

node query(node *tree, int start, int end, int treenode, int left, int right)
{
    node mini;
    mini.maximum = INT_MIN;
    mini.smaximum = -100001;
    //completely outside
    if (start > right || end < left)
    {
        return mini;
    }
    //completely inside
    if (start >= left && end <= right)
    {
        return tree[treenode];
    }

    int mid = (start + end) / 2;
    node ans = query(tree, start, mid, 2 * treenode, left, right);
    node ans2 = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
    node fanswer;
    fanswer.maximum = max(ans.maximum, ans2.maximum);
    fanswer.smaximum = min(max(ans.maximum, ans2.smaximum), max(ans2.maximum, ans.smaximum));

    return fanswer;
}

int main()
{
    int n, q;
    cin >> n;
    int *a = new int[n];
    node *tree = new node[3 * n];

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
        cin >> c >> l >> r;
        if (c == 'Q')
        {
            cout << query(tree, 0, n - 1, 1, l - 1, r - 1).maximum + query(tree, 0, n - 1, 1, l - 1, r - 1).smaximum << endl;
        }
        if (c == 'U')
        {
            updateTree(a, tree, 0, n - 1, 1, l - 1, r);
        }
    }
}