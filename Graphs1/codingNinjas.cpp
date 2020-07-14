/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/

//code
bool findmatch(char graph[][MAXN], string pat, int x, int y, int n, int m, int level){
    int l = pat.length();

    if (level == l){
        return true;
    }
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return false;
    }
    if (graph[x][y] == pat[level])
    {
        char temp = graph[x][y];
        graph[x][y] = '1';
         bool res = findmatch(graph, pat, x+1, y, n, m, level+1) |
                    findmatch(graph, pat, x, y+1, n, m, level+1) |
                    findmatch(graph, pat, x-1, y, n, m, level+1) |
                    findmatch(graph, pat, x, y-1, n, m, level+1) |
                    findmatch(graph, pat, x-1, y-1, n, m, level+1) |
                    findmatch(graph, pat, x-1, y+1, n, m, level+1) |
                    findmatch(graph, pat, x+1, y-1, n, m, level+1) |
                    findmatch(graph, pat, x+1, y+1, n, m, level+1) ;
        
         graph[x][y] = temp;  
        return res;
    }
    else{
        return false;
    }
    
}

bool checkmatch(char graph[][MAXN],string pat,int n,int m){
    
    int l = pat.length(); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == pat[0]){
                if(findmatch(graph, pat, i, j, n, m, 0)){
                    return true;
                }
            }
        }
    }
    return false;
}

int solve(char Graph[][MAXN],int N, int M)
{
	string pat = "CODINGNINJA";
    if(checkmatch(Graph, pat, N, M)){
        return 1;
    }
    else{
        return 0;
    }
    
    
}