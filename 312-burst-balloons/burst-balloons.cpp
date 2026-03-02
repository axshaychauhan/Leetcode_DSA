class Solution {
public:
    int solveMemoiation(vector<int>& nums, int left, int right,vector<vector<int>>& dp) {
        if(left > right)
           return 0;

        if(dp[left][right] != -1)
           return dp[left][right];

        int maxCoins = INT_MIN;
        for(int i = left; i<=right; ++i) {
        int  coins = nums[left-1] * nums[i] * nums[right+1] + solveMemoiation(nums, left, i - 1, dp) + solveMemoiation(nums, i+1, right, dp);
          maxCoins = max(coins, maxCoins);
        }
        return dp[left][right] = maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size() +1 , -1));
        return solveMemoiation(nums, 1, nums.size()-2, dp);
    }
};