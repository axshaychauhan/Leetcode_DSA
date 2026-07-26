class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right =  (int) nums.size() - 1;
        int leftRef = nums[0];

        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= leftRef) {
                if(target >= leftRef && target < nums[mid]){
                    right = mid -1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};