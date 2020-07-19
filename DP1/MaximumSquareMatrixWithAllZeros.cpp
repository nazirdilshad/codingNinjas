/*
Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/

//code
int min(int x,int y){
    int z = x>y?y:x;
    return z;
}
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int n = row, m = col;
    int **b = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        b[i] = new int[m + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            b[i][j] = 0;
        }
    }
    int max_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i - 1][j - 1] == 1)
            {
                continue;
            }
            else
            {
                b[i][j] = min(b[i - 1][j], min(b[i - 1][j - 1], b[i][j - 1])) + 1;
                if (b[i][j] > max_sum)
                {
                    max_sum = b[i][j];
                }
            }
        }
    }

    delete b;
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return max_sum;
    
}