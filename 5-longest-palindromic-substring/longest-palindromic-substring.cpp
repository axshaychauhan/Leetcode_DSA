class Solution {
public:
    string expandAroundCenter(string s, int start, int end) {

        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            --start;
            ++end;
        }

        return s.substr(start + 1 , end - start - 1);
    }
    string longestPalindrome(string s) {
        string answer = "";

        for (int i = 0; i < s.length(); ++i) {
            string oddPalin = expandAroundCenter(s, i, i);
            string evenPalin = expandAroundCenter(s, i, i + 1);

            string tempAnswer =
                oddPalin.length() > evenPalin.length() ? oddPalin : evenPalin;
            answer = answer.length() > tempAnswer.length() ? answer: tempAnswer;
        }
        return answer;
    }
};