class Solution {
public:
    string expand(int left, int right, string s){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            --left;
            ++right;
        }

        return s.substr(left+1, right - left - 1);
    }
    string longestPalindrome(string s) {
        int n = s.size();

        string longest = "";

        for(int i = 0; i<n; ++i){
            string odd = expand(i,i,s);
            string even = expand(i, i+1, s);

            string currLong = odd.size() > even.size() ? odd: even;

            if(currLong.size() > longest.size()){
                longest = currLong;
            }
        }

        return longest;
    }
};