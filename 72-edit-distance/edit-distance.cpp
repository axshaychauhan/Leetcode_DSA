class Solution {
public:
    int solveRecursion(string& word1, string& word2, int i, int j){
        if(i == word1.length())
           return word2.length() - j;
        if(j == word2.length())
           return word1.length() - i;

        int minOps = 0;
        if(word1[i] == word2[j])
          minOps = solveRecursion(word1, word2, i + 1, j+ 1);
        else {
           int insertOps = solveRecursion(word1, word2, i, j+1);
           int replaceOps = solveRecursion(word1, word2,i+1, j+1);
           int deleteOps = solveRecursion(word1, word2, i+1,j);
           minOps = min({insertOps, replaceOps, deleteOps}) + 1;
        }
        return minOps;  
    }
    int solveMemoiation(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        if(i == word1.length())
           return word2.length() - j;
        if(j == word2.length())
           return word1.length() - i;

        if(dp[i][j]!=  -1)
           return dp[i][j];

        int minOps = 0;
        if(word1[i] == word2[j])
          minOps = solveMemoiation(word1, word2, i + 1, j+ 1, dp);
        else {
           int insertOps = solveMemoiation(word1, word2, i, j+1, dp);
           int replaceOps = solveMemoiation(word1, word2,i+1, j+1, dp);
           int deleteOps = solveMemoiation(word1, word2, i+1,j, dp);
           minOps = min({insertOps, replaceOps, deleteOps}) + 1;
        }

        return dp[i][j] = minOps;
        
    }

     int solveTab(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        int m = word1.length();
        int n = word2.length();

        for(int i= 0; i<=m; i++)
           dp[i][0] = i;
        for(int j=0; j<=n; j++)
           dp[0][j] = j;

       for(int i = 1; i<=m; ++i) {
        for(int j= 1; j<=n; ++j) {
            if(word1[i-1] == word2[j-1])
               dp[i][j] = dp[i-1][j-1];
            else
               dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
        }
       }

       return dp[m][n];       
    }
    int minDistance(string word1, string word2) {
       
        vector<vector<int>> dp(word1.length() + 1,vector<int>(word2.length() + 1, 0));
   
        return solveTab(word1, word2, 0, 0, dp);
    }
};