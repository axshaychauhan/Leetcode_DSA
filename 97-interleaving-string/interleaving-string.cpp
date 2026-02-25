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
    bool isInterleave(string s1, string s2, string s3) {
        //return solve(s1,s2,s3,0,0);
        if(s1.length() + s2.length() != s3.length())
           return false;
        
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return solveMemoiation(s1, s2, s3, 0, 0, dp);
    }
};