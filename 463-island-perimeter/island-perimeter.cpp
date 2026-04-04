class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid) {

        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
            grid[row][col] == 0) {
            return 1;
        }
        if (grid[row][col] == -1) {
            return 0;
        }
        grid[row][col] = -1;
        int Perimeter = 0;

        Perimeter += dfs(row + 1, col, grid);
        Perimeter += dfs(row - 1, col, grid);
        Perimeter += dfs(row, col + 1, grid);
        Perimeter += dfs(row, col - 1, grid);

        return Perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int Perimeter = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] == 1) {
                    Perimeter = dfs(row, col, grid);
                    break;
                }
            }
        }
        return Perimeter;
    }
};