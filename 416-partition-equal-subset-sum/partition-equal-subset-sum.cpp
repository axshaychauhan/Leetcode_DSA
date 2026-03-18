class Solution {
public:

   bool solveRecursion(vector<int>& nums, int sum, int index) {
    
        if( sum == 0)
           return true;

        if(index >= nums.size())
           return false;


        return solveRecursion(nums, sum - nums[index], index + 1) || solveRecursion(nums, sum, index = 1);
   }

      bool solveMemoiation(vector<int>& nums, int sum, int index, vector<vector<int>>& dp) {
        if( sum == 0)
           return true;


        if(index >= nums.size() || sum < 0)
           return false;


        if(dp[sum][index] != -1)
           return dp[sum][index];


        return dp[sum][index] = solveMemoiation(nums, sum - nums[index], index + 1, dp) || solveMemoiation(nums, sum, index + 1, dp);
   }


    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        for(int num : nums)
           totalSum += num;

        if(totalSum % 2 != 0)
           return false;
         vector<vector<int>> dp(totalSum + 1, vector<int>(nums.size() + 1, -1));

        return solveMemoiation(nums, totalSum/2, 0, dp);
    }
};