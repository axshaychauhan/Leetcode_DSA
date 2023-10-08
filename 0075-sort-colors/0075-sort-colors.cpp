class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //we can use dutch national flag algorithm to solve this
        //take three pointer
        int first = 0;
        int mid = 0;
        int last = nums.size()-1;
        
        while(mid<=last) {
            
            //if element is 0 then swap it with first that will put all zero in start
            if(nums[mid] == 0) {
                swap(nums[mid],nums[first]);
                first++;
                mid++;
            }
            
            
            //if element is 2 swap it with last that will put all 2 in end
            
            else if(nums[mid] == 2) {
                swap(nums[last],nums[mid]);
                last--;
            }
            
            //if elment is 1 then skip it
            else {
                mid++;
            }
        }
    }
};