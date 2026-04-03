class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 2)
                    q.push({r, c});
                else if(grid[r][c] == 1)
                    ++freshOranges;
            }
        }
        int minutes = 0;
        while (!q.empty() && freshOranges > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [row, col] = q.front();
                q.pop();

                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                    --freshOranges;
                }
                if (row + 1 < grid.size() && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                    --freshOranges;
                }
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                    --freshOranges;
                }
                if (col + 1 < grid[0].size() && grid[row][col + 1] == 1)              {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                    --freshOranges;
                }
            }
            minutes++;
        }
        if(freshOranges > 0)
           return -1;
        else
           return minutes;
    }
};