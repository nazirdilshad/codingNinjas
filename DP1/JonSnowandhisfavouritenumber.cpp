/*
Jon Snow now has to fight with White Walkers. He has n rangers, each of which has his own strength. Also Jon Snow has his favourite number x. Each ranger can fight with a white walker only if the strength of the white walker equals his strength. He however thinks that his rangers are weak and need to improve. Jon now thinks that if he takes the bitwise XOR of strengths of some of rangers with his favourite number x, he might get soldiers of high strength. So, he decided to do the following operation k times:
Arrange all the rangers in a straight line in the order of increasing strengths.
Take the bitwise XOR of the strength of each alternate ranger with x and update it's strength.
Suppose, Jon has 5 rangers with strengths [9, 7, 11, 15, 5] and he performs the operation 1 time with x = 2. He first arranges them in the order of their strengths, [5, 7, 9, 11, 15]. Then he does the following:
The strength of first ranger is updated to 5 xor 2, i.e. 7.
The strength of second ranger remains the same, i.e. 7.
The strength of third ranger is updated to 9 xor 2, i.e. 11.
The strength of fourth ranger remains the same, i.e. 11.
The strength of fifth ranger is updated to 15 xor 2, i.e. 13.
The new strengths of the 5 rangers are [7, 7, 11, 11, 13]
Now, Jon wants to know the maximum and minimum strength of the rangers after performing the above operations k times. He wants your help for this task. Can you help him?
Input
First line consists of three integers n, k, x (1 ≤ n ≤ 10^5, 0 ≤ k ≤ 10^5, 0 ≤ x ≤ 10^3) — number of rangers Jon has, the number of times Jon will carry out the operation and Jon's favourite number respectively.

Second line consists of n integers representing the strengths of the rangers a1, a2, ..., an (0 ≤ ai ≤ 10^3).
Output
Output two integers, the maximum and the minimum strength of the rangers after performing the operation k times.
Sample Input
5 1 2
9 7 11 15 5
Sample Output
13 7
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
