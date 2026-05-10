class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // defind direction array
        // define 2D minimum efforts array
        // define priority queue [effort, row, col]
        // insert top left cell in pq
        // traverse pq
        // if cell is bottom right return miniEfforts[cell]
        // if efforts is
        // check all four direction
        // check if they are inbound
        // check if absolute difference beetwin current cell and new cell
        // if its less then update miniEffort
        int maxRowSize = heights.size();
        int maxColSize = heights[0].size();
        int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        vector<vector<int>> minEfforts(maxRowSize,
                                       vector<int>(maxColSize, INT_MAX));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>
            pq;

        pq.push({0, 0, 0});
        minEfforts[0][0] = 0;

        while (!pq.empty()) {
            auto [effort, row, col] = pq.top();
            pq.pop();

            if (row == maxRowSize - 1 && col == maxColSize - 1) {
                return effort; //do not return minEffort[row][col] it can contain stale effort
            }

            if(effort > minEfforts[row][col]) continue; // if effort is greater via this path then continue

            for (auto dir : directions) {
                int nRow = dir[0] + row;
                int nCol = dir[1] + col;

                if (nRow >= 0 && nRow < maxRowSize && nCol >= 0 &&
                    nCol < maxColSize) {
                    int newHeight = heights[nRow][nCol];
                    int currHeight = heights[row][col];
                    int jump = abs(currHeight - newHeight);
                    int newEffort = max(effort, jump);//newEffort will be max of current Jump and previous Max Effort

                    if (newEffort < minEfforts[nRow][nCol]) {
                        minEfforts[nRow][nCol] = newEffort;
                        pq.push({newEffort, nRow, nCol});
                    }
                }
            }
        }

        return 0;
    }
};