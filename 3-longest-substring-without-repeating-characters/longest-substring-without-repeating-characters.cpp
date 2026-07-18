class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_set<char> st;
        int left = 0;
        int maxLength = 0;
        for (int right = 0; right < (int)s.size(); ++right) {

while(st.find(s[right]) != st.end()) st.erase(s[left++]);
st.insert(s[right]);
maxLength = max(maxLength, (int)st.size());
        }
        return maxLength;
    }
};