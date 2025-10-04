class Solution {
public:
    int solveRecursion(vector<int>& coins, int target) {
        // Base case if target is zero means you found a way else you did not so
        // return INT_MAX for min function.
        if (target == 0)
            return 0;
        if (target < 0)
            return INT_MAX;

        int mini = INT_MAX;

        // will try all coins
        for (int i = 0; i < coins.size(); ++i) {

            int ans = solveRecursion(coins, target - coins[i]);
            if (ans != INT_MAX)
                mini = min(mini, 1 + ans);
        }

        return mini;
    }

    int solveMemo(vector<int>& coins, int target, vector<int>& dp) {
        // Base case if target is zero means you found a way else you did not so
        // return INT_MAX for min function.
        if (target == 0)
            return 0;
        if (target < 0)
            return INT_MAX;
        if (dp[target] != -1)
            return dp[target];
        int mini = INT_MAX;

        // will try all coins
        for (int i = 0; i < coins.size(); ++i) {

            int ans = solveMemo(coins, target - coins[i], dp);
            if (ans != INT_MAX)
                mini = min(mini, 1 + ans);
        }

        return dp[target] = mini;
    }

    int solveTab(vector<int>& coins, int target, vector<int>& dp) {
        // Base case if target is zero means you found a way else you did not so
        // return INT_MAX for min function.
        dp[0] = 0;

        // will try all coins
        for (int t = 1; t <= target; t++) {
            for (int i = 0; i < coins.size(); ++i) {
                if (t - coins[i] >= 0 && dp[t - coins[i]] != INT_MAX) {
    dp[t] = min(dp[t], 1 + dp[t - coins[i]]);
}
            }
        }
        return dp[target];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);

        int ans = solveTab(coins, amount, dp);
        if (ans != INT_MAX)
            return ans;
        else
            return -1;
    }
};