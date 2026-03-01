class Solution {
public:
    bool solveRecursion(string s, string p, int i, int j) {
    
    if(j == p.length())
       return i == s.length();


    bool isMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));


    if(j < p.length() && p[j + 1] == '*') {
        bool move1 = solveRecursion(s, p, i, j + 2);

        bool move2 = isMatch && solveRecursion(s, p, i+1, j);

        return move1 || move2;
    }
    if(isMatch)
       return solveRecursion(s, p, i+1, j+1);


    return false;
    }

    bool solveMemoiation(string s, string p, int i, int j, vector<vector<int>>& dp) {
    
    if(j == p.length())
       return i == s.length();

     if (dp[i][j] != -1)
        return dp[i][j];

    bool isMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));


    if(j + 1 < p.length() && p[j + 1] == '*') {
        bool move1 = solveMemoiation(s, p, i, j + 2, dp);

        bool move2 = isMatch && solveMemoiation(s, p, i+1, j, dp);

        return dp[i][j] = move1 || move2;
    }
    if(isMatch)
       return dp[i][j] = solveMemoiation(s, p, i+1, j+1, dp);

    return dp[i][j] = false;

    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return solveMemoiation(s, p, 0, 0, dp);
    }
};