class Solution {
public:
    long long solveRecursion(int row, int col, vector<vector<int>>& grid, int rowMax, int colMax) {
        //base case
        if(row == rowMax && col == colMax)
           return grid[row][col];
        if(row > rowMax || col > colMax)
          return INT_MAX;

        //our answer can come from down or right
        long long ansDown = grid[row][col] + solveRecursion(row + 1, col, grid, rowMax, colMax);

        long long ansRight = grid[row][col] + solveRecursion(row, col + 1, grid, rowMax, colMax);


        return min(ansDown, ansRight);
    }
    int solveMemoiation(int row, int col, vector<vector<int>>& grid, int rowMax, int colMax, vector<vector<int>>& dp) {
        if(row == rowMax && col == colMax)
           return grid[row][col];

        if(row > rowMax || col > colMax)
          return INT_MAX;

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        return dp[row][col] = grid[row][col] + min(solveMemoiation(row+1, col, grid, rowMax, colMax, dp), solveMemoiation(row, col+1, grid, rowMax, colMax, dp));

    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, -1));
        return solveMemoiation(0, 0, grid, grid.size()-1, grid[0].size()-1, dp);
        solveRecursion(0, 0, grid, grid.size()-1, grid[0].size()-1);
    }
};