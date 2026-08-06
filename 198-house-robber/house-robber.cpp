class Solution {
public:
    int solve(vector<int>& nums, int index){
        if(index >= nums.size())
            return 0;
        
        int pick = nums[index] + solve(nums, index + 2);
        int notPick = solve(nums, index + 1);

        return max(pick, notPick);

    }

    int solveMemo(vector<int>& nums, int index, vector<int>& dp) {
        if(index >= nums.size()) return 0;

        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + solveMemo(nums, index + 2, dp);

        int notPick = solveMemo(nums, index + 1, dp);

        return dp[index] = max(pick, notPick);
    }

    int optimized(vector<int>& nums, int n){
        if(n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for(int i = 2; i<n; ++i){
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        return optimized(nums,nums.size());
        if(nums.size() == 1) return nums[0];
        vector<int> dp (nums.size(), 0);
       // return solveMemo(nums,0, dp);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i<nums.size(); ++i){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[nums.size() - 1];

    }
};