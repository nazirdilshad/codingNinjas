/*
Edit Distance - Problem
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/

//code

#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int distance(string s1, string s2, int m, int n, int **dp)
{
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (s1[0] == s2[0])
    {
        dp[m][n] = distance(s1.substr(1), s2.substr(1), m - 1, n - 1, dp);
    }
    else
    {
        dp[m][n] = 1 + min(distance(s1, s2.substr(1), m, n - 1, dp), min(distance(s1.substr(1), s2, m - 1, n, dp), distance(s1.substr(1), s2.substr(1), m - 1, n - 1, dp)));
    }

    return dp[m][n];
}

int editDistance(string s1, string s2)
{

    /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int n = s1.length();
    int m = s2.length();
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[m + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = -1;
        }
    }

    int x = distance(s1, s2, n, m, dp);

    for (int i = 0; i <= n; i++)
    {
        delete dp[i];
    }
    delete[] dp;
    return x;
}
