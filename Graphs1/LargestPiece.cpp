/*
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3
*/

//code
int check(char cake[NMAX][NMAX],int n, int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= n)
    {
        return 0;
    }
    int count = 0;
    if(cake[x][y] == '1'){
        cake[x][y]= '#';
        count += 1 + check(cake, n, x+1, y) + check(cake, n, x, y+1) + check(cake, n, x-1, y) + check(cake, n, x, y-1) ;
        return count ;
    }
    else
    {
        return 0;
    }
}

int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
    int max = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cake[i][j] == '1'){
                int x = check(cake, n, i, j);
                if(x > max){
                    max = x;
                }
            }
        }
    }
    return max;
}