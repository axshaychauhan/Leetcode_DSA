class Solution {
public:
    int expandAroundCenter(string& s, int start, int end) {

        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            --start;
            ++end;
        }

        return end - start - 1;
    }
    string longestPalindrome(string s) {
       int start = 0;
       int max_length = 0;

        for (int i = 0; i < s.length(); ++i) {
            int oddPalinLength = expandAroundCenter(s, i, i);
            int evenPalinLength = expandAroundCenter(s, i, i + 1);

            int tempMaxLength = oddPalinLength > evenPalinLength ? oddPalinLength : evenPalinLength;

            if(tempMaxLength > max_length) {
                start = i - (tempMaxLength - 1) / 2;
                max_length = tempMaxLength;
            }
        }
        return s.substr(start, max_length);
    }
};