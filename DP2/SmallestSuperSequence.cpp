/*
Smallest Super-Sequence
Send Feedback
Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings. 
Sample Input:
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3.
*/

//code

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


int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    string s1 = "",s2="";
    for(int i=0;i<len1;i++){
        s1+=str1[i];
    }
    for(int i=0;i<len2;i++){
        s2+=str2[i];
    }
    int y= lcs(s1,s2);
    int x = len1 + (len2-y);
    return x;

}