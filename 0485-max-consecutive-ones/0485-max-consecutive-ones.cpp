class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cons = 0;
        int ans = 0;
        
        int i=0;
        
        while(i<nums.size()) {
            if(nums[i] == 1) {
                int j = i;
                while(j<nums.size() && nums[j] == 1){
                    cons++;
                    j++;
                }
                
                i = j-1;
            }
            
            else {
                cons = 0;
            }
            
            ++i;
            if(cons>ans){
                
                ans = cons;
                
            }
        }
        
        
        return ans;
    }
};