class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        if (nums.empty())
            return 0;
        int size = (int)nums.size();
        long long currentSum = 0;
        long long maxSum = 0;
        int distinct = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < size; ++i) {
            currentSum += nums[i];
            if (++freq[nums[i]] == 1)
                ++distinct;
            if (i >= k) {
                currentSum -= nums[i - k];
                if (--freq[nums[i - k]] == 0)
                    --distinct;
                ;
            }
            if (i >= k - 1 && distinct == k) {
                if (freq[nums[i]] == 1)
                    maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
};