class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        int prevHold = -prices[0];
        int prevSold = 0;
        int prevRest = 0;

        for(int i = 1; i<n; i++) {
            int tempHold = prevHold;
            int tempSold = prevSold;
            prevHold = max(prevHold, prevRest - prices[i]);
            prevSold = tempHold + prices[i];
            prevRest = max(prevRest, tempSold);

        }

        return max(prevSold,prevRest);
    }
};