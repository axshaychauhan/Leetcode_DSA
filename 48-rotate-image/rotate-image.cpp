class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int) matrix.size();
        for(int i =0; i<n; ++i){
            for(int j = i+1; j<n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int row =0; row<n; ++row){
            int left = 0; int right = n - 1;

            while(left < right){
                swap(matrix[row][left++], matrix[row][right--]);
            }
        }
    }
};