class Solution {
public:
    int trap(vector<int>& height) {
        int size = int(height.size());
        vector<int> leftMax(size);
        leftMax[0] = height[0];
        vector<int> rightMax(size);
        rightMax[size-1] = height[size-1];
        int trappedWater = 0;

        for(int i = 1; i<size; ++i) leftMax[i] = max(leftMax[i-1], height[i]);
        for(int j = size-2; j>= 0; --j) rightMax[j] = max(rightMax[j+1], height[j]);

        for(int i = 0; i<size; ++i) trappedWater += min(leftMax[i], rightMax[i]) - height[i];

        return trappedWater;
    }
};