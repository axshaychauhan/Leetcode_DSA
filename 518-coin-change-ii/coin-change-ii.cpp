class Solution {
public:
int solveRecursion(vector<int>& coins, int target, int index, vector<vector<int>>& dp) {
    // Base Cases
    if (target == 0) return 1;
    if (target < 0) return 0;
    if (index >= coins.size()) return 0;

    if(dp[target][index] != -1)
       return dp[target][index];

    // 1. Take (Remember: you can reuse it!)
    int take = solveRecursion(coins, target - coins[index], index, dp);

    // 2. Skip c (Move to the next coin)
    int skip = solveRecursion(coins, target, index + 1, dp);

    return dp[target][index] = take + skip;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, -1));
        return solveRecursion(coins, amount, 0, dp);
    }
};