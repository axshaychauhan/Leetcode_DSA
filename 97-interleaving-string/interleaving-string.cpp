class Solution {
public:
    bool solve(string s1, string s2, string s3, int i, int j){
        if(i == s1.length() && j== s2.length())
           return true;
        
        bool ans = false;

        if(i < s1.length() && s1[i] == s3[i+j] )
           ans = ans || solve(s1, s2, s3, i+1, j);
        if(j < s2.length() && s2[j] == s3[i+j])
           ans = ans || solve(s1, s2, s3, i, j+1);

        return ans;
    }

    bool solveMemoiation(string s1, string s2, string s3, int i, int j, vector<vector<int>> &dp){
         if(i == s1.length() && j == s2.length())
            return true;

        if(dp[i][j] != -1)
           return dp[i][j];


        int ans = false;

        if(i < s1.length() && s1[i] == s3[i+j])
           ans = ans || solveMemoiation(s1, s2, s3, i+1, j, dp);

        if(j < s2.length() && s2[j] == s3[i+j])
           ans = ans || solveMemoiation(s1, s2, s3, i, j+1, dp);

        return dp[i][j] = ans;
    }
bool solveTab(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        // Edge Case Crash Prevention
        if (m + n != s3.length()) return false;

        // STEP 1: Create the DP table (Size is +1 for the base case)
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // STEP 2: The Base Case 
        // (Translated from: if(i == m && j == n) return true;)
        dp[m][n] = true;

        // STEP 3: The Dependency Check 
        // Because your recursion called (i+1) and (j+1), we must loop BACKWARDS.
        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                
                // Skip the base case since it's already true
                if (i == m && j == n) continue;

                bool ans = false;

                // ==========================================
                // STEP 4: YOUR TURN!
                // Paste your two recursive 'if' statements here.
                // Replace 'solveMemoiation(...)' with 'dp[...][...]'
                // ==========================================
                
                // 1. If we take from s1...
                if(i < s1.length() && s1[i] == s3[i+j])
                    ans = ans || dp[i+1][j];
                // 2. If we take from s2...
                if(j < s2.length() && s2[j] == s3[i+j])
                    ans = ans || dp[i][j+1];

                dp[i][j] = ans;
            }
        }

        // The answer to the original question (starting at index 0,0)
        return dp[0][0];
    }

bool solveSpaceOptimized(string s1, string s2, string s3) {
    int m = s1.length();
    int n = s2.length();
    
    if (m + n != s3.length()) return false;

    // STEP 1: A single 1D array of size n + 1
    vector<bool> dp(n + 1, false);

    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            
            // STEP 2: The Base Case
            if (i == m && j == n) {
                dp[j] = true;
                continue;
            }

            bool ans = false;

            // ==========================================
            // STEP 3: YOUR TURN!
            // Paste your logic, but use the 1D Translation Key!
            // Replace dp[i+1][j] with dp[j]
            // Replace dp[i][j+1] with dp[j+1]
            // ==========================================
            
            // 1. If we take from s1...
            if(i < s1.length() && s1[i] == s3[i+j])
                ans = ans || dp[j];
            
            // 2. If we take from s2...
            if(j < s2.length() && s2[j] == s3[i+j])
                ans = ans || dp[j + 1];

            dp[j] = ans;
        }
    }

    // The answer is at the front of the array!
    return dp[0];
}

    bool isInterleave(string s1, string s2, string s3) {
        //return solve(s1,s2,s3,0,0);
       // if(s1.length() + s2.length() != s3.length())
       //    return false;
        
       // vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return solveTab(s1, s2, s3);
       //return solveSpaceOptimized(s1, s2, s3);
    }
};