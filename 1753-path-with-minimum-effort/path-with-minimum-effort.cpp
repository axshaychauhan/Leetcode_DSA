class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //define directions array
        //define distance 2d array
        //define priority quueue
        //add topleft cell into quque
        //traverse queue 
        //if you reach bottom right direction return effort
        //if distance > distance[cell] continue;
        //loop through all directions
        //check if they are inbound
        //if efforts of current cell + neghbouring cells < distance[neighbouring cell] update it
        //keep doing this
        int rowSize = heights.size();
        int colSize = heights[0].size();

        int directions[4][2] = {{-1,0}, {1, 0} ,{0, -1}, {0, 1}};
        

        vector<vector<int>> distance(rowSize, vector<int>(colSize, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        distance[0][0] = 0;

        while(!pq.empty()) {
            int effort = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();

            if(row == rowSize - 1 && col == colSize - 1) return effort;

            if(effort > distance[row][col]) continue;

            for(auto& dir : directions) {
                int nRow = row + dir[0];
                int nCol = col + dir[1];

                if(nRow < 0 || nCol < 0 || nRow >= rowSize || nCol >= colSize) continue;
                int newEffort = max(effort, abs(heights[row][col] - heights[nRow][nCol]));
                if(newEffort < distance[nRow][nCol]) {
                    distance[nRow][nCol] = newEffort;
                    pq.push({distance[nRow][nCol], nRow, nCol});
                }
            }
        }
        return 0;
    }
};