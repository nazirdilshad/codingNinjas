/*
LCS - Problem
Send Feedback
Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of lcs
Sample Input :
adebc
dcadb
Sample Output :
3
*/

//code:

#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int lcs(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int n= s1.length();
    int m = s2.length();
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[m+1];
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[n-i]==s2[m-j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans= dp[n][m];
    for(int i=0;i<=n;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
    
}
