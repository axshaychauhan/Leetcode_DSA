class Solution {
public:
    int trap(vector<int>& height) {

        return trapTwoPointer(height);
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

    int trapTwoPointer(vector<int>& height){
        int size = int(height.size());
        int left = 0;
        int right = size - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while(left < right){
            if(height[left] < height[right]){
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            }
            else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                --right;
            }
        }
        return water;
    }
};