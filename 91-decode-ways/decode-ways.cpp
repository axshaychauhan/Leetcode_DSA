class Solution {
public:
    int solve(string s, int i, vector<int>& dp) {
        // base case : if we reach end of string means we found one way to
        // decode
        int next1 = 1;
        int next2 = 0;
        for (i = s.size() - 1; i >= 0; --i) {
            // single digit
            int curr = 0;

            if (s[i] != '0')
                curr += next1;
            // double digit
            if (i + 1 < s.size() &&
                (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
                curr += next2;

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        vector<int> dp(s.size() + 1, 0);
        return solve(s, 0, dp);
    }
};