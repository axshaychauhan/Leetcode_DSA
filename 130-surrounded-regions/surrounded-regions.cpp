class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] != 'O') return;

        grid[row][col] = 'T';

        dfs(row - 1, col, grid);
        dfs(row + 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }
    void solve(vector<vector<char>>& board) {
        int maxRow = board.size();
        int maxCol = board[0].size();

        //traverse from boundary and mark all o and coonected o to T
        //traverse again and mark remaining O X and T back to O.

        for(int row = 0; row < maxRow; ++row) {
            if(board[row][0] == 'O') dfs(row, 0, board);
            if(board[row][maxCol-1] == 'O') dfs(row, maxCol-1, board);
        }

        for(int col = 0; col < maxCol; ++col) {
             if(board[0][col] == 'O')dfs(0, col, board);
             if(board[maxRow - 1][col] == 'O')dfs(maxRow - 1, col, board);
        }

        for(int r = 0 ; r < maxRow; ++r) {
            for(int c = 0; c < maxCol; ++c) {
                if(board[r][c] == 'O') board[r][c] = 'X';
                if(board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
};