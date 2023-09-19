class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int cons = 0;
       int ans = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                while(i<nums.size() && nums[i] == 1) {
                    i++;
                    cons++;
                }
                --i;
            }
            
            else {
                cons = 0;
            }
            
            
            if(cons>ans)
                    ans = cons;
            
        }
        
        return ans;
    }
};