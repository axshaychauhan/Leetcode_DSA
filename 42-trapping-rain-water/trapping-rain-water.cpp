class Solution {
public:
    int trap(vector<int>& height) {
        int size = int(height.size());
        vector<int> maxLeft(size);
        maxLeft[0] = height[0];
        vector<int> maxRight(size);
        maxRight[size - 1] = height[size - 1];

        for (int i = 1; i < size; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        for (int j = size - 2; j >= 0; --j) {
            maxRight[j] = max(maxRight[j + 1], height[j]);
        }

        int totalTappedWater = 0;
        for(int i = 0; i< size; ++i){
             totalTappedWater += min(maxLeft[i] , maxRight[i]) - height[i];
            
        }
        return totalTappedWater;
    }
};