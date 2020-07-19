/*
Trader Profit
Send Feedback
Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
The stock prices are given in the form of an array A for n days.
Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
Input Format
The first line of input contains an integer q denoting the number of queries.

The first line of each test case contains a positive integer k, denoting the number of transactions. 

The second line of each test case contains a positive integer n, denoting the length of the array A.

The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.
Constraints
1<=q<=100

0<k<10

2<=n<=30

0<=elements of array A<=1000
Output Format
For each query print the maximum profit earned by Mike on a new line. 
Sample Input
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25
Sample Output
87
1040
0
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
