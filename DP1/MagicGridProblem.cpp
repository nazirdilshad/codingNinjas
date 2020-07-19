/*
You are given a magrid S ( a magic grid ) having R rows and C columns. Each cell in this magrid has either a Hungarian horntail dragon that our intrepid hero has to defeat, or a flask of magic potion that his teacher Snape has left for him. A dragon at a cell (i,j) takes away |S[i][j]| strength points from him, and a potion at a cell (i,j) increases Harry's strength by S[i][j]. If his strength drops to 0 or less at any point during his journey, Harry dies, and no magical stone can revive him.
Harry starts from the top-left corner cell (1,1) and the Sorcerer's Stone is in the bottom-right corner cell (R,C). From a cell (i,j), Harry can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and he can not move outside the magrid. Harry has used magic before starting his journey to determine which cell contains what, but lacks the basic simple mathematical skill to determine what minimum strength he needs to start with to collect the Sorcerer's Stone. Please help him once again.
Input (STDIN)
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with S[i][j] < 0 contain dragons, others contain magic potions.
Output (STDOUT):
Output T lines, one for each case containing the minimum strength Harry should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).
Constraints:
1 ≤ T ≤ 5

2 ≤ R, C ≤ 500

-10^3 ≤ S[i][j] ≤ 10^3

S[1][1] = S[R][C] = 0
Sample Input
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0
Sample Output
2
1
2
*/

//code
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int r,c;
    cin>>r>>c;
    int** input = new int*[r];
    for(int i=0;i<r;i++){
        input[i]=new int[c];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>input[i][j];
        }
    }
    int** output = new int*[r];
    for(int i=0;i<r;i++){
        output[i]=new int[c];
    }
    
    output[r-1][c-1]=1;
    
    
    for(int i=r-2;i>=0;i--){
        if(input[i][c-1]<=0){
            output[i][c-1]= output[i+1][c-1]-input[i][c-1];
        }
        else if(input[i][c-1]<output[i+1][c-1]){
            output[i][c-1]= (output[i+1][c-1]-input[i][c-1]);
        }
        else if(input[i][c-1]>=output[i+1][c-1]){
            output[i][c-1]= 1;
        }
        
        
        
        
               
    }
    for(int j=c-2;j>=0;j--){
        if(input[r-1][j]<=0){
            output[r-1][j]=output[r-1][j+1]-input[r-1][j];
        }
        else if(input[r-1][j]<output[r-1][j+1]){
            output[r-1][j]=(output[r-1][j+1]-input[r-1][j]);
        }
        else if(input[r-1][j]>=output[r-1][j+1]){
            output[r-1][j]=1;
        }
        // else{
        //     output[r-1][j]=input[r-1][j]-output[r-1][j+1]; 
        // }
        
       
    }
    
    
    for(int i=r-2;i>=0;i--){
        for(int j=c-2;j>=0;j--){
            if(input[i][j]<=0){
                output[i][j]= min(output[i+1][j],output[i][j+1])-input[i][j];
            }
            else if(input[i][j]<min(output[i+1][j],output[i][j+1])){
                output[i][j]=  min(output[i+1][j],output[i][j+1])-input[i][j];
            }
            else if (input[i][j]>=min(output[i+1][j],output[i][j+1])){
                output[i][j]= 1;
            }
            // else{
            //     output[i][j]= input[i][j]-min(output[i+1][j],output[i][j+1]);
            // }
            
        }
    }
    
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout<<output[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    int x = output[0][0];
    delete [] output;
    cout<<x<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
