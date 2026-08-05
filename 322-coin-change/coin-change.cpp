class Solution {
public:
    int solve(vector<int>& coins, int target) {
        if (target == 0)
            return 0;

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] <= target) {
                int ans = solve(coins, target - coins[i]);
                if (ans != INT_MAX) {
                    mini = min(mini, 1 + ans);
                }
            }
        }

        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1,amount + 1);
        dp[0] = 0;

        for(int t = 1; t<= amount ; ++t){
            for(int c = 0; c < coins.size(); ++c){
                if(coins[c] <= t){
                    dp[t] = min(dp[t], dp[t - coins[c]] + 1);
                }
            }
        }

        return dp[amount] == amount + 1? -1: dp[amount];
    }
};