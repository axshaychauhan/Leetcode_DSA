class Solution {
public:
    int solveRecursion(vector<int>& nums, int target, int index) {
        if (index >= nums.size()) {
            if (target == 0)
                return 1;
            else
                return 0;
        }

        int add = solveRecursion(nums, target - nums[index], index + 1);

        int sub = solveRecursion(nums, target + nums[index], index + 1);

        return add + sub;
    }

    int solveMemoiation(vector<int>& nums, int target, int index,
                        vector<vector<int>>& dp, int totalSum) {
        if (index >= nums.size()) {
            if (target == 0)
                return 1;
            else
                return 0;
        }
        //Need to remeber below edge case
        if (abs(target) > totalSum) {
            return 0;
        }
        if (dp[target + totalSum][index] != -1)
            return dp[target + totalSum][index];

        int add = solveMemoiation(nums, target - nums[index], index + 1, dp,
                                  totalSum);

        int sub = solveMemoiation(nums, target + nums[index], index + 1, dp,
                                  totalSum);

        return dp[target + totalSum][index] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // Run Recursive solution solve(nums, target, 0);
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (abs(target) > totalSum) {
            return 0;
        }
        vector<vector<int>> dp(2 * totalSum + 1,
                               vector<int>(nums.size() + 1, -1));
        return solveMemoiation(nums, target, 0, dp, totalSum);
    }
};