class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board) {
         int n = board.size();
         int m = board[0].size();

         if(row < 0 || col < 0 || row >= n || col >= m || board[row][col] != 'O')
         return;

         board[row][col] = 'T';

         dfs(row + 1, col, board);
         dfs(row - 1, col, board);
         dfs(row, col + 1, board);
         dfs(row, col - 1, board);

    }
    void solve(vector<vector<char>>& board) {
        //Marks Borders Regions
        int n = board.size();
        int m = board[0].size();
        int topRow = 0;
        int bottomRow = n - 1;
        int leftCol = 0;
        int rightCol = m - 1;

        for(int col = 0; col <m; ++col) {
            if(board[topRow][col] == 'O') {
                dfs(topRow, col, board);
            }
            if(board[bottomRow][col] == 'O') {
                dfs(bottomRow, col, board);
            }
        }
        for(int row = 0; row < n; ++row) {
            if(board[row][leftCol] == 'O') {
                dfs(row, leftCol, board);
            }
            if(board[row][rightCol] == 'O') {
                dfs(row, rightCol, board);
            }
        }

        for(int row = 0; row<n; ++row) {
            for(int col = 0; col <m; ++ col) {
                if(board[row][col] == 'O')
                    board[row][col] = 'X';
                else if(board[row][col] == 'T')
                    board[row][col] = 'O';
            }
        }
        
    }
};