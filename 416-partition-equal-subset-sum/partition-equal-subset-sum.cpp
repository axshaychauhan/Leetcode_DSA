class Solution {
public:
    // Recursion
    bool solveRecursion(int index, vector<int>& arr, int sum, int currSum) {
        if (index >= arr.size())
            return false;
        if (currSum == sum)
            return true;

        return solveRecursion(index + 1, arr, sum, currSum + arr[index]) ||
               solveRecursion(index + 1, arr, sum, currSum);
    }

    // Memoiation
    bool solveMemo(int index, vector<int> &arr, int sum, vector<vector<int>>&dp) {
        if (sum == 0)
            return true;
            
        if(index >= arr.size() || sum < 0)
            return false;

        if(dp[index][sum] != -1)
           return dp[index][sum];
           
        return dp[index][sum] =  solveMemo(index+1, arr, sum - arr[index], dp) ||
                                 solveMemo(index+1, arr, sum, dp);
        
    }

    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 != 0)
            return false;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(totalSum / 2 + 1, -1));
            
         return solveMemo(0, nums, totalSum / 2, dp);
    }
};