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
    int solveTab(int row, int col, vector<vector<int>>& grid, int rowMax, int colMax) {
        vector<vector<long long>> dp(grid.size(), vector<long long>(grid[0].size(), INT_MAX));
            dp[rowMax][colMax] = grid[rowMax][colMax];

            for(int i = rowMax; i >=0 ; --i){
                for(int j = colMax; j >= 0; --j) {
                    if(i == rowMax && j == colMax)
                       continue;

                   dp[i][j] = grid[i][j] + min(i < rowMax? dp[i+1][j]: INT_MAX, j < colMax? dp[i][j+1]:INT_MAX);
                }
            }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        return solveTab(0, 0, grid, grid.size()-1, grid[0].size()-1);

        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, -1));
        solveMemoiation(0, 0, grid, grid.size()-1, grid[0].size()-1, dp);
        solveRecursion(0, 0, grid, grid.size()-1, grid[0].size()-1);
    }
};