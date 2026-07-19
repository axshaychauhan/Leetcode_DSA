class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n == 0)
            return 0;

        int left = 0;
        long long maxSumSoFar = 0;
        long long maxSum = 0;
        int distinct = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < n; ++right) {
            maxSumSoFar += nums[right];
            if (++freq[nums[right]] == 1)
                ++distinct;
            if (right >= k) {
                maxSumSoFar -= nums[left];
                if (--freq[nums[left]] == 0)
                    --distinct;
                ++left;
            }
            if (right >= k - 1 && distinct == k) {
                maxSum = max(maxSum, maxSumSoFar);
            }
        }
        return maxSum;
    }
};