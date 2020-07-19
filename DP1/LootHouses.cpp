/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110
*/

//code
int max(int x,int y){
    return x>y?x:y;
    
}
int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    if(n==1){
        return arr[0];    
    }
    if(n==2){
        return max(arr[0],arr[1]);
    }
    
    // int dp[n];
    // dp[0]=arr[0];
    // dp[1]=max(arr[0],arr[1]);
    // for(int i=2;i<n;i++){
    //     dp[i]=max(dp[i-1],arr[i]+dp[i-2]); 
    // }
    // return dp[n-1];
    
    
    int value1 = arr[0];
    int value2 = max(arr[0],arr[1]);
    int max_value;
    for(int i=2;i<n;i++){
        max_value = max(value1+arr[i],value2);
        value1=value2;
        value2 = max_value;
        
    }
    return max_value;

}
