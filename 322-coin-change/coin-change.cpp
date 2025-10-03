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

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);

        int ans = solveMemo(coins, amount, dp);
        if (ans != INT_MAX)
            return ans;
        else
            return -1;
    }
};