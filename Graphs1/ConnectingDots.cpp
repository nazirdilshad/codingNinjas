/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1
*/

//code
int visited[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int cnt;
bool dfs(char board[][MAXN], int n, int m, char tar , int row, int col, int fx, int fy) {
    if(visited[row][col]) {
        if(cnt >= 4) {
            return true;
        } else {
            return false;
        }
    }
    cnt++;
    visited[row][col] = 1;

    for(int i = 0; i < 4; i++) {

        if(fx == row + dx[i] && fy == col + dy[i])
            continue;
        if(row + dx[i] < n && row + dx[i] >= 0) {
            if(col + dy[i] < m && col + dy[i] >= 0) {
                if(board[row + dx[i]][col + dy[i]] == tar) {
                   bool f = dfs(board, n, m, tar, row + dx[i], col + dy[i] , row, col);
                   if(f) {
                       return true;
                   }
                }
            }
        }
    }

    return false;
}

int solve(char board[][MAXN],int n, int m)
{
    memset(visited, 0, sizeof visited);
	char ch = 'A';
    bool flag;
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < m ; k++) {
            if(!visited[j][k]) {
                cnt = 0;
                flag = dfs(board, n, m, board[j][k], j , k, -1,-1);
                if(flag) {
                    return 1;
                }
            }
        }
    }
    return 0;
}