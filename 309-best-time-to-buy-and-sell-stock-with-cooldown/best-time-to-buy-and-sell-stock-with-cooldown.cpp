class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        vector<int> hold(n, 0);
        vector<int> sold(n, 0);
        vector<int> rest(n, 0);

        hold[0] = -prices[0];
        sold[0] = 0;
        rest[0] = 0;
    //  hold state today = max(i was holding yesterday, i bought yesterday);
    //   sold state today = i was holding yesterday
    //   rest state today = max(i was resting yesterday , i sold yesterday);
        for(int i = 1; i<n; ++i) {
            hold[i] = max(hold[i-1], rest[i-1] - prices[i]);
            sold[i] = hold[i-1] + prices[i];
            rest[i] = max(rest[i-1], sold[i-1]);
        }


        return max(sold[n-1], rest[n-1]);
    }
};