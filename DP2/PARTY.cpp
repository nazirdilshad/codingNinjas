/*
PARTY - Problem
Send Feedback
You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
Input
The first line of the input specifies your party budget and the number n of parties.

The following n lines contain two numbers each. The first number indicates the entrance fee of each party. Parties cost between 5 and 25 francs. The second number indicates the amount of fun of each party, given as an integer number ranging from 0 to 10.

The budget will not exceed 500 and there will be at most 100 parties. All numbers are separated by a single space.

There are many test cases. Input ends with 0 0.
Output
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space. 
Sample Input
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0
Sample Output
49 26
48 32
*/

//code
// #include <bits/stdc++.h>
// using namespace std;



// int main()
// {
//     int b,p;
//     cin>>b>>p;
//     int* bud = new int[p];
//     int* party = new int[p];
//     for(int i=0;i<p;i++){
//         cin>>bud[i]>>party[i];
//     }
//     budgetcheck(bud,party,b,p);
//     int** dp = new int*[p+1];
//     for(int i=0;i<=n;i++){
//         dp[i]= new int[b+1];
//     }
//     for(int i=0;i<=b;i++){
//         dp[0][i];
//     }
//     for(int i=0;i<=p;i++){
//         dp[i][0];
//     }
//     for(int i=1;i<=p;i++){
//         for(int j=0;j<=b;j++){
//             dp[i][j]= dp[i-1][j];
//             if(bud[i]<=j){
//                 dp[i][j]=max(dp[i][w],)
//             }
//         }
//     }
//     return 0;
// }

//It doesn't matter how slow you go, Unless you don't stop.
#include<iostream>
#include<algorithm>
#include<bitset>
 
#include<cmath>
#include<cstring>
#include<climits>
 
#include<deque>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
 
#include<fstream>
#include<chrono>
using namespace std;
 
typedef long long LL;
typedef pair<LL,LL> p64;
typedef vector<LL> v64;
typedef map<LL,LL> mp64;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,s,e) for(long long i=s;i<=e;i++)
#define brep(i,s,e) for(long long i=s;i>=e;i--)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define DANGER std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void solve()
{
     while(true)
     {
         int money,n;
         cin>>money>>n;
         if(money == 0) {
             return;
         }
         int entry[n+1];
         int franc[n+1];
         for(int i=0;i<n;i++)
         {
             cin>>entry[i];
             cin>>franc[i];
         }

         int **  dp = new int *  [101];
         for(int i=0;i<=n;i++)
         {
             dp[i] = new int[501];
         }
         for(int i=0;i<=n;i++)
         {
             for(int j=0;j<=500;j++)
             {
                 dp[i][j] = 0;
             }
         }
         
         //dp solve
         for(int i=0;i<=n;i++)
         {
             for(int ent=0;ent<=money;ent++)
             {
                 if(i==0 || ent==0)
                 {
                     dp[i][ent] = 0;
                 }
                 else if(entry[i-1] <=ent){
          dp[i][ent]= max((franc[i-1] +dp[i-1][ent-entry[i-1]]),dp[i-1][ent]);
        }else{
          dp[i][ent]=dp[i-1][ent];
        }
             }
         }

         int res=0;
        for(int i=0;i<=money;i++)
        {
            if(dp[n][i] == dp[n][money])
            {
                res = i;
                break;
            }
        }
         cout<<res<<" "<<dp[n][money]<<endl;
     }
     return;
}
 
int main()
{
    DANGER;
    ofstream out("output.txt");
 
    auto start = chrono::high_resolution_clock::now();
    
    LL t = 1;
    // cin>>t;
    rep(test,1,t)
    {
        solve();
    }
    
    auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); 
    // cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
}