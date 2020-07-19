/*
Shortest Subsequence
Send Feedback
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Sample Input :
babab
babba
Sample Output :
3
*/

//code
int dp[1028][1028];

int shortestSubsequence(string s1,string s2,int l1,int l2){
    if(l1==0)
        return 10001;
    if(l2<=0)
        return 1;
    
    if(dp[l1][l2]!=-1){
        return dp[l1][l2];
    }
    int k=-1;
    k=s2.find(s1[0]);
    if(k==-1){
        return 1;
    }
    int y = shortestSubsequence(s1.substr(1),s2,l1-1,l2);
    int z = 1 + shortestSubsequence(s1.substr(1),s2.substr(k+1),l1-1,l2-k-1);
    
    dp[l1][l2]=min(y,z);
    return dp[l1][l2];
}
int solve(string S,string V)
{
	// Write your code here.
    memset(dp,-1,sizeof dp);
    int l1 = S.length();
    int l2 = V.length();
    return shortestSubsequence(S,V,l1,l2);
}


