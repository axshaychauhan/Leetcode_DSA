class Solution {
public:
    // ONE universal DFS engine for both oceans!
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& ocean, int prevHeight) {
        int n = grid.size();
        int m = grid[0].size();

        // 1. Bounds check
        // 2. Visited check (ocean[row][col] == true)
        // 3. Uphill check (grid[row][col] < prevHeight)
        if (row < 0 || col < 0 || row >= n || col >= m || 
            ocean[row][col] || grid[row][col] < prevHeight) {
            return;
        }

        // Mark as reachable (and visited!)
        ocean[row][col] = true;

        // Flood in all 4 directions, passing the CURRENT cell's height as the new baseline
        dfs(row + 1, col, grid, ocean, grid[row][col]);
        dfs(row - 1, col, grid, ocean, grid[row][col]);
        dfs(row, col + 1, grid, ocean, grid[row][col]);
        dfs(row, col - 1, grid, ocean, grid[row][col]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        // Sweep Left and Right borders
        for (int row = 0; row < n; ++row) {
            dfs(row, 0, heights, pac, heights[row][0]);         // Left (Pacific)
            dfs(row, m - 1, heights, atl, heights[row][m - 1]); // Right (Atlantic)
        }

        // Sweep Top and Bottom borders
        for (int col = 0; col < m; ++col) {
            dfs(0, col, heights, pac, heights[0][col]);         // Top (Pacific)
            dfs(n - 1, col, heights, atl, heights[n - 1][col]); // Bottom (Atlantic)
        }

        // The Intersection Sweep
        vector<vector<int>> ans;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) { // Fixed typo: col < m
                if (pac[row][col] && atl[row][col]) {
                    ans.push_back({row, col});
                }
            }
        }
        return ans;
    }
};