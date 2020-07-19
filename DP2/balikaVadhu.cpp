/*
Balika Vadhu- Problem
Send Feedback
Anandi and Jagya were getting married again when they have achieved proper age. Dadi Sa invited Alok Nath to do the kanyadaan and give blessings. Alok Nath has 2 blessings. Each bessing is in the form of a string consisting of lowercase charaters(a-z) only. But he can give only one blessing of K length because some priest told him to do so. Thus he decides to generate a blessing using the other two blessings. While doing this he wants to ensure that happiness brought into their life by his blessing is maximum.
The generated blessing is a common subsequence of length K of the two blessings he has. Happiness of the blessing he generates is calculated by the sum of ASCII values of characters in the blessing and he wants the happiness to be maximum. If he is not able to generate a common subsequence of length K then the happiness is 0 (zero). Alok Nath comes to you and asks you to find the maximum happiness that can be generated by the two blessings he has.
Input Specification
First line consists of number of test cases t. Each test case consists of two strings b1 (blessing 1),b2 (blessing 2) and an integer K, each of them in separate lines.
Output Specification
Output consists of t lines each containing an integer denoting the maximum happiness value that can be generated by the two blessings.
Constraint
1 <= t <= 50

1 <= length(b1) , length(b2) <= 100 

1 <= K <= 100
Sample Input
2
asdf
asdf
3
anandi
jagya
3
Sample Output
317
0
*/

//code
#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];

int maxhappiness(string s1,string s2, int n, int m, int k){
    if(k==0){
        return 0;
    }
    if((n==0 || m==0) && k!=0){
        return -100000;
    }
    if(dp[n][m][k]!=-1){
        return dp[n][m][k];
    }
    
     if (s1[0] == s2[0])
    {
         int x = s1[0];
        dp[n][m][k] = max(maxhappiness(s1.substr(1), s2.substr(1), n - 1, m - 1,k-1)+x,max(maxhappiness(s1, s2.substr(1), n, m - 1,k),maxhappiness(s1.substr(1), s2, n - 1, m ,k)));
    }
    else
    {
        dp[n][m][k] = max(maxhappiness(s1, s2.substr(1), n, m - 1,k),maxhappiness(s1.substr(1), s2, n - 1, m ,k));
    }
    return dp[n][m][k];
}

void solve(){
    string s1,s2;
    int k;
    cin>>s1>>s2>>k;
    
    memset(dp,-1,sizeof dp);
    int res = maxhappiness(s1,s2,s1.length(),s2.length(),k);
    if(res>0)
    {
        cout<<res<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
