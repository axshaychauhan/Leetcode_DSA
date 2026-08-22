class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n,1);
        
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int rightProduct = 1;
        for (int j = n - 1; j >= 0; --j) {
            ans[j] = ans[j] * rightProduct;
            rightProduct *= nums[j];
        }
        return ans;
    }
};