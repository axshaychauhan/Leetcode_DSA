class Solution {
public:
    int firstOccurance(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;
        while(start<=end) {
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target) {
                ans = mid;
                end = mid-1;
            }
            
            else if(nums[mid] > target) {
                end = mid -1;
            }
            
            else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
    
    
    int lastOccurance(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;
        while(start<=end) {
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target) {
                ans = mid;
                start = mid + 1;
            }
            
            else if(nums[mid] > target) {
                end = mid -1;
            }
            
            else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int firstOcc = firstOccurance(nums,target) ;
        int lastOcc = lastOccurance(nums,target);
        ans.push_back(firstOcc);
        ans.push_back(lastOcc);
        return ans;
        
    }
};