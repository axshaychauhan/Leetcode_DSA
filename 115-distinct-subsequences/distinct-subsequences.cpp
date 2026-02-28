class Solution {
public:


    int solveRecursion(string& s, string& t, int i, int j) {
        if (j == t.length())
            return 1;
        if (i == s.length())
            return 0;

        int ans = 0;

        if (s[i] == t[j])
            ans = solveRecursion(s, t, i + 1, j + 1) +
                  solveRecursion(s, t, i + 1, j);
        else
            ans = solveRecursion(s, t, i + 1, j);

        return ans;
    }

    int solveMemoiation(string& s, string& t, int i, int j, vector<vector<long long>>& dp) {
        if (j == t.length())
            return 1;
        if (i == s.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if (s[i] == t[j])
            ans = solveMemoiation(s, t, i + 1, j + 1, dp) +
                  solveMemoiation(s, t, i + 1, j, dp);
        else
            ans = solveMemoiation(s, t, i + 1, j, dp);

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) { 
            vector<vector<long long>> dp(s.length() + 1,
                                 vector<long long>(t.length() + 1, -1));
        return solveMemoiation(s, t, 0, 0, dp); }
};