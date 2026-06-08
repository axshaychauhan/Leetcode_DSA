class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        int mini = INT_MAX;
        for (int coin : coins) {
            if(coin <= amount){
            int sub = solve(coins, amount - coin);
            if (sub != INT_MAX)
                mini = min(mini, 1 + sub);
            }
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;
        for(int target = 1; target <= amount; ++target) {
            for(int coin: coins) {
                if(coin <= target && dp[target - coin] != INT_MAX) {
                    dp[target] = min(dp[target], 1 + dp[target - coin]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }


};