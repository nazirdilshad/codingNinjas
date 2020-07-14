/*Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
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
    ll odd;
    ll even;
};
void buildtree(int *a, node *tree, int start, int end, int treenode)
{
    if (start == end)
    {
        if (a[start] % 2)
        {
            tree[treenode].odd = 1;
            tree[treenode].even = 0;
        }
        else
        {
            tree[treenode].even = 1;
            tree[treenode].odd = 0;
        }
        return;
    }
    int mid = (start + end) / 2;
    buildtree(a, tree, start, mid, 2 * treenode);
    buildtree(a, tree, mid + 1, end, 2 * treenode + 1);

    node left = tree[2 * treenode];
    node right = tree[2 * treenode + 1];

    tree[treenode].odd = left.odd + right.odd;
    tree[treenode].even = left.even + right.even;
    return;
}

void updateTree(int *a, node *tree, int start, int end, int treenode, int idx, int value)
{
    if (start == end)
    {
        a[idx] = value;
        if (value % 2)
        {
            tree[treenode].odd = 1;
            tree[treenode].even = 0;
        }
        else
        {
            tree[treenode].even = 1;
            tree[treenode].odd = 0;
        }
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

    tree[treenode].odd = left.odd + right.odd;
    tree[treenode].even = left.even + right.even;
}

node query(node *tree, int start, int end, int treenode, int left, int right)
{
    node minni;
    minni.odd = minni.even = 0;
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
    fanswer.odd = left1.odd + right1.odd;
    fanswer.even = left1.even + right1.even;

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
        cin >> c >> l >> r;
        if (c == '1')
        {
            cout << query(tree, 0, n - 1, 1, l - 1, r - 1).even << endl;
        }
        if (c == '0')
        {
            updateTree(a, tree, 0, n - 1, 1, l - 1, r);
        }
        if (c == '2')
        {
            cout << query(tree, 0, n - 1, 1, l - 1, r - 1).odd << endl;
        }
    }
}