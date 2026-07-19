class Solution {
public:
    string minWindow(string s, string t) {
        int bestStart = -1;
        int bestLength = INT_MAX;
        if (t.size() > s.size())
            return "";
        unordered_map<int, int> need;
        unordered_map<int, int> window;
        int left = 0;
        int have = 0;

        for (char c : t)
            ++need[c - 'A'];
        for (int right = 0; right < (int)s.size(); ++right) {
            int ch = s[right] - 'A';
            ++window[ch];
            if (need.find(ch) != need.end() && need[ch] == window[ch])
                ++have;
            if (have == need.size()) {

                while (have == need.size()) {
                    if (bestStart == -1 || right - left + 1 < bestLength) {
                        bestStart = left;
                        bestLength = right - left + 1;
                    }
                    ch = s[left++] - 'A';
                    if (need.find(ch) != need.end() && --window[ch] == need[ch] - 1)
                        --have;
                }
            }
        }
        return bestStart == -1? "" : s.substr(bestStart, bestLength);
    }
};