class Solution {
public:
    int solveRecursion(vector<int>& coins, int target) {
        if(target == 0)
           return 0;
        if(target < 0)
           return INT_MAX;

        int mini = INT_MAX;
        for(int coin: coins) {
          int ans = solveRecursion(coins, target - coin);
          if(ans != INT_MAX)
             mini = min(mini,1 + ans);
        }
        return mini;
    }

        int solveMemoiation(vector<int>& coins, int target, vector<int>& dp) {
        if(target == 0)
           return 0;
        if(target < 0)
           return INT_MAX;
        if(dp[target] != -1)
           return dp[target];

        int mini = INT_MAX;
        for(int coin: coins) {
          int ans = solveMemoiation(coins, target - coin, dp);
          if(ans != INT_MAX)
             mini = min(mini,1 + ans);
        }
        return dp[target] = mini;
    }

    int solveTab(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int target = 1; target <= amount; ++target) {
            for(int i = 0; i < coins.size(); ++i) {
                if(target - coins[i] >= 0 && dp[target - coins[i]]  != INT_MAX)
    dp[target] = min(dp[target],1 + dp[target - coins[i]]);
           }
        }

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
            int mini = solveTab(coins, amount);
            return mini == INT_MAX ? -1: mini;
    }
};