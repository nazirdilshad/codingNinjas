/*
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5
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
    ll amaximum;
    ll bmaximum;
    ll index;
};
void buildtree(ll *a, ll *b, node *tree, int start, int end, int treenode)
{
    if (start == end)
    {
        tree[treenode].amaximum = a[start];
        tree[treenode].bmaximum = b[start];
        tree[treenode].index = start;
        return;
    }
    int mid = (start + end) / 2;
    buildtree(a, b, tree, start, mid, 2 * treenode);
    buildtree(a, b, tree, mid + 1, end, 2 * treenode + 1);

    node left = tree[2 * treenode];
    node right = tree[2 * treenode + 1];
    if (left.amaximum == right.amaximum)
    {
        if (left.bmaximum < right.bmaximum)
        {
            tree[treenode].amaximum = left.amaximum;
            tree[treenode].bmaximum = left.bmaximum;
            tree[treenode].index = left.index;
        }
        else if (left.bmaximum > right.bmaximum)
        {
            tree[treenode].amaximum = right.amaximum;
            tree[treenode].bmaximum = right.bmaximum;
            tree[treenode].index = right.index;
        }
        else
        {
            if (left.index < right.index)
            {
                tree[treenode].amaximum = left.amaximum;
                tree[treenode].bmaximum = left.bmaximum;
                tree[treenode].index = left.index;
            }
            else
            {
                tree[treenode].amaximum = right.amaximum;
                tree[treenode].bmaximum = right.bmaximum;
                tree[treenode].index = right.index;
            }
        }
    }
    else
    {
        if (left.amaximum > right.amaximum)
        {
            tree[treenode].amaximum = left.amaximum;
            tree[treenode].bmaximum = left.bmaximum;
            tree[treenode].index = left.index;
        }
        else
        {
            tree[treenode].amaximum = right.amaximum;
            tree[treenode].bmaximum = right.bmaximum;
            tree[treenode].index = right.index;
        }
    }
    return;
}



node query(node *tree, int start, int end, int treenode, int left, int right)
{
    node minni;
    minni.amaximum = -100000;
    minni.bmaximum = 100000000;
    minni.index = 1000000;
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
    if (left1.amaximum == right1.amaximum)
    {
        if (left1.bmaximum < right1.bmaximum)
        {
            fanswer.amaximum = left1.amaximum;
            fanswer.bmaximum = left1.bmaximum;
            fanswer.index = left1.index;
        }
        else if (left1.bmaximum > right1.bmaximum)
        {
            fanswer.amaximum = right1.amaximum;
            fanswer.bmaximum = right1.bmaximum;
            fanswer.index = right1.index;
        }
        else
        {
            if (left1.index < right1.index)
            {
                fanswer.amaximum = left1.amaximum;
                fanswer.bmaximum = left1.bmaximum;
                fanswer.index = left1.index;
            }
            else
            {
                fanswer.amaximum = right1.amaximum;
                fanswer.bmaximum = right1.bmaximum;
                fanswer.index = right1.index;
            }
        }
    }
    else
    {
        if (left1.amaximum > right1.amaximum)
        {
            fanswer.amaximum = left1.amaximum;
            fanswer.bmaximum = left1.bmaximum;
            fanswer.index = left1.index;
        }
        else
        {
            fanswer.amaximum = right1.amaximum;
            fanswer.bmaximum = right1.bmaximum;
            fanswer.index = right1.index;
        }
    }

    return fanswer;
}

int main()
{
    ll n, q;
    cin >> n;
    ll *a = new ll[n];
    ll *b = new ll[n];
    node *tree = new node[4 * n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cin >> q;
    char c;
    int l, r;
    buildtree(a, b, tree, 0, n - 1, 1);

    for (int i = 1; i < 2 * n; i++)
    {
        //cout << tree[i].amaximum << " " << tree[i].bmaximum << "\n ";
    }
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        
        cout << query(tree, 0, n - 1, 1, l - 1, r - 1).index + 1 << endl;
    }
}
