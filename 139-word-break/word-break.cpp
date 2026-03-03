class Solution {
public:
    bool solveRecursion(int start, string& s, unordered_set<string>& dict) {

        if (start == s.length())
            return 1;

        for (int wordEnd = start + 1; wordEnd <= s.length(); ++wordEnd) {
            string word = s.substr(start, wordEnd - start);

            if (dict.count(word)) {
                if (solveRecursion(wordEnd, s, dict) == 1)
                    return 1;
            }
        }

        return 0;
    }

    bool solveMemoiation(int start, string& s, unordered_set<string>& dict,
                         vector<int>& dp) {

        if (start == s.length())
            return 1;

        if (dp[start] != -1)
            return dp[start];
        string substring = "";
        for (int wordEnd = start; wordEnd <= s.length(); ++wordEnd) {
           substring.push_back(s[wordEnd]);

            if (dict.count(substring)) {
                if (solveMemoiation(wordEnd + 1, s, dict, dp) == 1)
                    return dp[start] = 1;
            }
        }

        return dp[start] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length() + 1, -1);
        return solveMemoiation(0, s, dict, dp);
    }
};