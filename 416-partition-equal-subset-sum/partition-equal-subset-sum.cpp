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
           
        return dp[index][sum] =  solveMemo(index+1, arr, sum - arr[index], dp) || solveMemo(index+1, arr, sum, dp);
        
    }


    //space optimized tabulation
    bool isSubsetSum(std::vector<int>& arr, int sum) {
        // dp array to track which sums are possible
        // dp[j] is true if a sum of j is achievable
        std::vector<bool> dp(sum + 1, false);
        
        // Base case: A sum of 0 is always possible with an empty subset.
        dp[0] = true;
        
        // Iterate through each number in the input array
        for (int num : arr) {
            
            // Iterate backward through the possible sums.
            // This is crucial to ensure each element is used at most once.
            for (int j = sum; j >= num; --j) {
                // The current sum j can be formed if:
                // 1. It was already possible before considering the current number (dp[j])
                // OR
                // 2. We can achieve it by taking the current number, which means
                //    the remaining sum (j - num) was possible before.
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        // The final answer is whether the target sum is achievable.
        return dp[sum];
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
            
         return isSubsetSum(nums, totalSum / 2);
    }
};