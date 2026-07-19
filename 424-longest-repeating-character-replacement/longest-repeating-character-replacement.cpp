class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq [26] = {0};
        int left = 0;
        int maxCountMajority = 0;
        int best = 0;

        for(int right = 0; right< (int)s.size(); ++right) {
            int currentWindowSize = right - left + 1;
            maxCountMajority = max(maxCountMajority, ++freq[s[right] - 'A']);
            if(currentWindowSize - maxCountMajority > k){
                --freq[s[left] - 'A'];
                ++left;
                currentWindowSize--;
            }
            best = max(best, currentWindowSize);
        }
        return best;
    }
};