class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 2)
                    q.push({r, c});
                else if (grid[r][c] == 1)
                    ++freshOranges;
            }
        }
        int minutes = 0;
        while (!q.empty() && freshOranges > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [row, col] = q.front();
                q.pop();

                for (auto dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    // One single, clean boundary and validation check
                    if (newRow >= 0 && newRow < n && newCol >= 0 &&
                        newCol < m && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        freshOranges--;
                    }
                }
            }
            minutes++;
        }
        if (freshOranges > 0)
            return -1;
        else
            return minutes;
    }
};