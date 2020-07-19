/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/

//code
long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    long* a = new long[n+1];
    a[0]=1;
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=n;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    long x = a[n];
    delete [] a;
    return x;
    
    
}
