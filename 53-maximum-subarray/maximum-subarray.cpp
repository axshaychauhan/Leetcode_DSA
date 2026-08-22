class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int prevBest = 0;

        for(int num: nums){
            prevBest = max(prevBest + num, num);

            maxSum = max(maxSum, prevBest);
        }

        return maxSum;
    }
};