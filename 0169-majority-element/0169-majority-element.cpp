class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int i=0; i<nums.size(); i++) {
            count[nums[i]]++;
        }
        
        int max = -1;
        int ans = -1;
        for(auto element:count) {
            
            if(element.second>max) {
                max = element.second;
                ans = element.first;
            }
        }
        
        return ans;
    }
};