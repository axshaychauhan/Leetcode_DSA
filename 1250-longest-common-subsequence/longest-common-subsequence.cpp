class Solution {
public:
    int solveRecursion(int i, int j,string s1, string s2) {
        //base case
        if(i == s1.length() || j == s2.length())
           return 0;

        if(s1[i] == s2[j])
           return 1 + solveRecursion(i+1, j+1, s1, s2);
        else 
           return max(solveRecursion(i+1, j, s1, s2), solveRecursion(i, j+1, s1, s2));

           
    }

    int solveMemoiation(int i, int j,string& s1, string& s2, vector<vector<int>>& dp) {
        //base case
        if(i == s1.length() || j == s2.length())
           return 0;
        if(dp[i][j] != -1)
           return dp[i][j];

        if(s1[i] == s2[j])
           return dp[i][j] = 1 + solveMemoiation(i+1, j+1, s1, s2, dp);
        else 
           return dp[i][j] = max(solveMemoiation(i+1, j, s1, s2, dp), solveMemoiation(i, j+1, s1, s2, dp));  
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length() + 1, -1));
        return solveMemoiation(0, 0, text1, text2, dp);
    }
};