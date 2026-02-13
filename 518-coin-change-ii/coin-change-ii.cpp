class Solution {
public:
int solveBottomUp(int amount, vector<int>& coins) {
    int n = coins.size();
    // Create DP table: n rows, amount+1 columns
    // Initialize with 0
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // Base Case: Target 0 is always 1 way
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    
    // Fill the table
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= amount; j++) {
            long notTake = 0, take = 0;
            // 1. Calculate 'Skip' (Not taking coin i)
            // Be careful: if i == 0, there is no previous coin!
            if( i != 0)
              notTake = dp[i-1][j];

            // 2. Calculate 'Take' (Taking coin i)
            // Check if j >= coins[i] first
            if(j >= coins[i]) 
                take =  dp[i][j - coins[i]];

            // Store sum
            dp[i][j] = take + notTake;
        }
    }
    
    // The answer is at the last coin, full amount
    return dp[n - 1][amount];
}
    int change(int amount, vector<int>& coins) {
        return solveBottomUp(amount, coins);
    }
};