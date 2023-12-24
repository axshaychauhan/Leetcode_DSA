class Solution {
public:
    int myAtoi(string s) {

        double ans = 0;
        bool positive;
        bool negative;
        int i = 0;

        // skipping leading whitespaces
        while (s[i] == ' ')
            ++i;

        // checking sign
        negative = s[i] == '-';
        positive = s[i] == '+';

        // if sign present move to next char
        if (negative || positive)
            ++i;

        // if char is betwn 0 to 9 add it to ans
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            char ch = s[i];
            int digit = ch - '0';
            ans = ans * 10 + digit;
            ++i;
        }

        // add sign to ans
        ans = negative == true ? -ans : ans;

        // check for INT_MIN or INT_MAX
        ans = ans >= INT_MAX ? INT_MAX : ans;
        ans = ans <= INT_MIN ? INT_MIN : ans;

        return ans;
    }
};