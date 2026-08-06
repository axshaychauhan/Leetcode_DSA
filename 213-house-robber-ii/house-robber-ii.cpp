class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        if(start == end) return nums[start];
         
        int prev2 = nums[start];
        int prev1 = max(prev2, nums[start+1]);

        for(int i = start + 2; i<=end; ++i){
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(solve(nums,0, nums.size() - 2), solve(nums,1,nums.size()-1));
    }
};