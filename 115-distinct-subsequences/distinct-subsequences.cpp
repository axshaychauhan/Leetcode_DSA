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

        long long ans = 0;

        if (s[i] == t[j])
            ans = solveMemoiation(s, t, i + 1, j + 1, dp) +
                  solveMemoiation(s, t, i + 1, j, dp);
        else
            ans = solveMemoiation(s, t, i + 1, j, dp);

        return dp[i][j] = ans;
    }

    int solveTabulation(string s, string t) {

       vector<vector<unsigned long long>> dp(s.length() + 1, vector<unsigned long long>(t.length() + 1, 0)); 
        
        for(int i = 0; i<=s.length(); ++i){
            dp[i][t.length()] = 1;
        }
        
        for(int i = s.length()-1; i>=0 ; --i) {
            for(int j = t.length()-1; j>= 0; --j) {

                if(s[i] == t[j])
                   dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                else
                   dp[i][j] = dp[i+1][j];

            }
        }

        return int(dp[0][0]);
    }

    int solve1DTab(string s, string t) {
        
        // STEP 1: A single 1D array of size t.length() + 1
        vector<unsigned long long> dp(t.length() + 1, 0);

        // STEP 2: The Base Case 
        // When t is empty (index t.length()), we found 1 valid subsequence
        dp[t.length()] = 1;


        for(int i = s.length() - 1; i >= 0; --i) {
            

            for(int j = 0; j < t.length(); ++j) {
                           
                if (s[i] == t[j]) {
                    dp[j] = dp[j] + dp[j+1];
                } else {
                    dp[j] = dp[j];
                }
            }
        }

        // Cast safely back to int per LeetCode's guarantee
        return (int)dp[0];
    }


    int numDistinct(string s, string t) { 
          //  vector<vector<long long>> dp(s.length() + 1,
         //                        vector<long long>(t.length() + 1, -1));
        // solveMemoiation(s, t, 0, 0, dp);
       // return solveTabulation(s,t); 
        return solve1DTab(s,t);
        }
};