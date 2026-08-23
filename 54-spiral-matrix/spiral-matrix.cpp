class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int toprow = 0;
        int bottomrow = m - 1;
        int firstcol = 0;
        int lastcol = n - 1;
        vector<int> ans;

        while (toprow <= bottomrow && firstcol <= lastcol) {
            for (int col = firstcol; col <= lastcol; ++col) {
                ans.push_back(matrix[toprow][col]);
            }
            ++toprow;
            for (int row = toprow; row <= bottomrow; ++row) {
                ans.push_back(matrix[row][lastcol]);
            }
            --lastcol;
           if( toprow <= bottomrow) {
            for (int col = lastcol; col >= firstcol; --col) {
                ans.push_back(matrix[bottomrow][col]);
            }
            --bottomrow;
           }
           if(firstcol <= lastcol) {
            for (int row = bottomrow; row >= toprow; --row) {
                ans.push_back(matrix[row][firstcol]);
            }
            ++firstcol;
           }
        }

        return ans;
    }
};