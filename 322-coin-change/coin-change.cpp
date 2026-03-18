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

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
            int mini = solveMemoiation(coins, amount, dp);
            return mini == INT_MAX ? -1: mini;
    }
};