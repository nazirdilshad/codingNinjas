/*
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

//code
#include <bits/stdc++.h>

int dp[1001];
int getMinSquares(int n)
{
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;

    if (n <= 3 || dp[n] != -1)
        return dp[n];

    int xx = n;
    for (int x = 1; x * x <= n; x++)
    {
        int temp = x * x;
        if (temp > n)
            break;
        else
        {
            xx = min(xx, 1 + getMinSquares(n - temp));
        }
    }
    return dp[n] = xx;
}

int minCount(int n)
{

    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    memset(dp, -1, sizeof dp);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    return getMinSquares(n);
}