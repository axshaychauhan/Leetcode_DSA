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
    int rob(vector<int>& nums) {
        vector<int> dp (nums.size(), -1);
        return solveMemo(nums,0, dp);
    }
};