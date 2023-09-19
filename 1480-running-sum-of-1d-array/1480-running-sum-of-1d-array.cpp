class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i=0; i<nums.size(); i++) {
            if(i==0)
                ans[i]=nums[i];
            else 
                ans[i] = ans[i-1] + nums[i];
        }
        
        
        return ans;
    }
};