class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        int mini = INT_MAX;
        for (int coin : coins) {
            if (coin <= amount) {
                int sub = solve(coins, amount - coin);
                if (sub != INT_MAX)
                    mini = min(mini, 1 + sub);
            }
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;
        for (int target = 1; target <= amount; ++target) {
            for (int coin : coins) {
                if (coin > target)
                    break;
                dp[target] = min(dp[target], 1 + dp[target - coin]);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};