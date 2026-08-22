class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProduct = 1;
        int maxProduct = 1;

        int ans = INT_MIN;

        for(int num: nums){
            int tempMin = minProduct * num;
            int tempMax = maxProduct * num;

             minProduct = min(min(tempMin, tempMax), num);

             maxProduct = max(max(tempMin, tempMax), num);
            
            ans = max(ans, maxProduct);

        }

        return ans;
    }
};