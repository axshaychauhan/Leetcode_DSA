class Solution {
public:
    int direction[4][2] = {{-1, 0}, {0, -1}, {+1, 0}, {0, +1}};
    int solveRecursion(vector<vector<int>>& matrix, int r, int c) {

        int max_path = 1;

        for (int d = 0; d < 4; ++d) {
            int next_row = r + direction[d][0];
            int next_col = c + direction[d][1];

            if (next_row >= 0 && next_row < matrix.size() && next_col >= 0 &&
                next_col < matrix[0].size() &&
                matrix[r][c] < matrix[next_row][next_col]) {
                max_path = max(max_path,
                               solveRecursion(matrix, next_row, next_col) + 1);
            }
        }

        return max_path;
    }
     
    int solveMemoiation(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
     
       if(dp[r][c] != -1)
          return dp[r][c];

        int max_path = 1;
        for (int d = 0; d < 4; ++d) {
            int next_row = r + direction[d][0];
            int next_col = c + direction[d][1];

            if (next_row >= 0 && next_row < matrix.size() && next_col >= 0 &&
                next_col < matrix[0].size() &&
                matrix[r][c] < matrix[next_row][next_col]) {
                max_path = max(max_path,
                               solveMemoiation(matrix, next_row, next_col, dp) + 1);
            }
        }

        return dp[r][c] = max_path;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int globalMax = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                globalMax = max(globalMax, solveMemoiation(matrix, r, c, dp));
            }
        }
        return globalMax;
    }
};