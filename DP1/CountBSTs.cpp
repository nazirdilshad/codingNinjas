/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/

//code
long long mod = 1e9+7;
int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    long long bst[n];
    bst[0]=1;
    bst[1]=1;
    long sum=2;
    for(int i=2;i<=n;i++){
        bst[i]=0;
        for(int j=0;j<i;j++){
            bst[i]=((bst[i] % mod)+ (((bst[j])%mod)*((bst[i-j-1])%mod))%mod)%mod;
           // bst[i] = bst[i] % mod;
        }
        
    }
    return bst[n];

}


