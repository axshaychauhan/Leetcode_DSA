class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid) {
        int n =  grid.size();
        int m =  grid[0].size();


        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0)
           return 0;

        grid[row][col] = 0;
        int AreaOfIsland = 0;

        AreaOfIsland +=  dfs(row - 1, col, grid);
        AreaOfIsland +=  dfs(row + 1, col, grid);
        AreaOfIsland +=  dfs(row, col + 1, grid);
        AreaOfIsland +=  dfs(row, col - 1, grid);

        return 1 + AreaOfIsland;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m =  grid[0].size();
        int maxArea = 0;
        
        for(int r = 0; r<n; ++r) {
            for(int c = 0; c<m; ++c) {
                if(grid[r][c] == 1) {
                  int areaIsland = dfs(r, c, grid);
                  maxArea = max(maxArea, areaIsland);
                }
            }
        }
        return maxArea;
    }
};