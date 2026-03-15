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
    int minDistance(string word1, string word2) {
       
        vector<vector<int>> dp(word1.length() + 1,vector<int>(word2.length() + 1, -1));
   
        return solveMemoiation(word1, word2, 0, 0, dp);
    }
};