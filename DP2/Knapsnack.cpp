/*
Knapsnack - Problem
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/

//code
#include <bits/stdc++.h>
using namespace std;
//int dp[31][11][2];

// int mincheck(int n,int k,int a[],int state){
//     if(n==0){
//         return 0;
//     }
//     if(state==0){
        
//         if(k>0){
//             mincheck(n-1,k-1,a+1,1);
//         }
//     }
//     if(state==1){
//         max(mincheck(n-1,k,a+1,1),mincheck(n-1,k-1,a+1,0));
//     }
    
    
// }

int maxi(int n,int k,int a[]){
    int dp[k+1][n];
    for(int i=0;i<n;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=k;i++){
        dp[i][0]=0;
    }
    
    for(int i=1;i<=k;i++){
        int maxdiff = dp[i-1][0]-a[0];
        for(int j=1;j<n;j++){
            dp[i][j]=max(dp[i][j-1],a[j]+maxdiff);
            maxdiff=max(maxdiff,dp[i-1][j]-a[j]);
        }
    }
    return dp[k][n-1];
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        //memset(dp,0,sizeof dp);
        int k,n;
        cin>>k>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<maxi(n,k,a)<<endl;
    }
    return 0;
}
