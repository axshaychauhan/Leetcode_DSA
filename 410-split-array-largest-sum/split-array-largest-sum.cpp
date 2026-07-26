class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int minSum = INT_MIN;
        int maxSum = 0;
        for(int num: nums){
            minSum = max(minSum,num);
            maxSum += num;
        }
        int ans  = -1;
        while(minSum <= maxSum){
            int mid = minSum + (maxSum - minSum)/2;
            if(canSplit(nums,k,mid)){
                ans = mid;
                maxSum = mid - 1;
            }
            else {
                minSum = mid + 1;
            }
        }

        return ans;
    }

    bool canSplit(vector<int>&nums, int k, int sum){
        int splitCount = 1;
        int currSum = 0;
        for(int num: nums){
            if(currSum + num <= sum){
                currSum += num;
            }
            else {
                currSum = num;
                ++splitCount;
            }
        }

        return splitCount <= k;
    }
};