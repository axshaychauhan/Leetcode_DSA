class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int maxProfit = 0;

        for(int i = 0; i<prices.size(); i++){
            maxProfit = max(maxProfit, prices[i] - minBuy);
            minBuy = min(minBuy, prices[i]);
        }

        return maxProfit;
    }
};