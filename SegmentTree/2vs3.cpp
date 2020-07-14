/*
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.
It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to 
solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
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

ll square[100015];
ll one = 1;
void buildtree(ll *a, ll *tree, int start, int end, int treenode)
{
    if (start == end)
    {
        tree[treenode] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    buildtree(a, tree, start, mid, 2 * treenode);
    buildtree(a, tree, mid + 1, end, 2 * treenode + 1);

    int x = end - mid;
    tree[treenode] = (tree[2 * treenode + 1] + (tree[2 * treenode] * square[x]) % 3) % 3;
    return;
}

void updateTree(ll *a, ll *tree, int start, int end, int treenode, int idx)
{
    if (start == end)
    {
        a[idx] = a[idx] | 1;
        tree[treenode] = a[idx];
        return;
    }
    int mid = (start + end) / 2;
    if (idx > mid)
    {
        updateTree(a, tree, mid + 1, end, 2 * treenode + 1, idx);
    }
    else
    {
        updateTree(a, tree, start, mid, 2 * treenode, idx);
    }
    int x = end - mid;
    tree[treenode] = (tree[2 * treenode + 1] + (tree[2 * treenode] * square[x]) % 3) % 3;
}

int query(ll *tree, int start, int end, int treenode, int left, int right)
{
    //completely outside
    if (start > right || end < left)
    {
        return 0;
    }
    //completely inside
    int x = right - end;
    if (start >= left && end <= right)
    {
        return (tree[treenode] * square[x]) % 3;
    }

    int mid = (start + end) / 2;
    int left1 = query(tree, start, mid, 2 * treenode, left, right);
    int right1 = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
    int ans = (right1 + left1) % 3;
    return ans;
}

int main()
{
    ll n, q;
    cin >> n;
    ll *a = new ll[n];
    ll *tree = new ll[4 * n];
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - '0';
    }
    square[0]=1;
    for (int i = 1; i < 100005; i++)
    {
        square[i] = 2*square[i-1];
        square[i] = square[i]%3;
    }
    buildtree(a, tree, 0, n - 1, 1);
    cin >> q;
    char c;
    int l, r;
    

    /*printing the tree
    for (int i = 1; i < 2 * n; i++)
    {
        cout << tree[i] << "\n";
    }
    */

    for (int i = 0; i < q; i++)
    {
        cin >> c;
        if (c == '0')
        {
            cin >> l >> r;
            cout << query(tree, 0, n - 1, 1, l, r) << endl;
        }
        if (c == '1')
        {
            cin >> l;
            updateTree(a, tree, 0, n - 1, 1, l);
        }
    }
}