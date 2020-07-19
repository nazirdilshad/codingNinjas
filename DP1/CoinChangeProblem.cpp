/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/

//code
int coin_change(int n,int* d,int num_d,int** output){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(num_d==0){
        return 0;
    }
    if(output[n][num_d]>-1){
        return output[n][num_d];
    }
    
    int first = coin_change(n-d[0],d,num_d,output);
    int second = coin_change(n,d+1,num_d-1,output);
    output[n][num_d]= first+ second;
    
    return first+second;
        
}

int countWaysToMakeChange(int coinarr[], int totalc, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int **output =  new int*[value+1];
    for(int i=0;i<=value;i++){
       output[i] = new int[totalc+1]; 
    }
        
        for(int i=0;i<=value;i++){
            for(int j=0;j<=totalc;j++){
                output[i][j]=-1;
            }  
        }
    int x = coin_change(value,coinarr,totalc,output);
     delete [] output;
    return x;
    


}
