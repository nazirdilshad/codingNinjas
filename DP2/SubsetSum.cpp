/*
Subset Sum - Problem
Send Feedback
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes
*/

//code
#include <bits/stdc++.h>
using namespace std;

bool subsetsum(int a[],int n,int k){
    bool check[2][k+1];
    for(int i=0;i<=k;i++){
        check[0][i]=false;
    }
    check[0][0]=true;
    int flag = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            check[flag][j]= check[flag^1][j];
            if(j>=a[i-1]){
                check[flag][j]=check[flag ^ 1][j] || check[flag ^ 1][j-a[i-1]];
            }
        }
        flag = flag ^ 1 ;
    }
    return check[flag^1][k];
}

int main()
{
    int n,k;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    if(subsetsum(a,n,k)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}
