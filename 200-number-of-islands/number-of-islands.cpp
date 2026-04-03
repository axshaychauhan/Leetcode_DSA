class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& grid) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0')
            return;
        grid[row][col] = '0';
        dfs(row - 1, col, grid);
        dfs(row + 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int numberOfIsland = 0;

        for(int r = 0; r<n; ++r) {
            for(int c =0 ; c<m; ++c) {
                if(grid[r][c] == '1') {
                    dfs(r, c, grid);
                    ++numberOfIsland;
                }
            }
        }
        return numberOfIsland;
    }
};