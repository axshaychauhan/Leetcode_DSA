class Solution {
public:
    vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int freshCount  = 0;
        int time = 0;
        int maxRow = grid.size();
        int maxCol = grid[0].size();

        for(int i = 0; i<maxRow; ++i){
            for(int j = 0; j<maxCol; ++j) {
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    ++freshCount;
                }
            }
        }

        while(freshCount > 0 && !q.empty()) {
            int sz = q.size();

            for(int i = 0; i< sz; ++i) {
                auto [row, col] = q.front();
                q.pop();

                for(auto d: dir){
                    int newRow = row + d[0];
                    int newCol = col + d[1];

                    if(newRow >= 0 && newRow < maxRow && newCol >= 0 && newCol < maxCol && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        --freshCount;
                    }
                }
            }
            ++time;
        }

        return freshCount == 0? time: -1;
    }
};