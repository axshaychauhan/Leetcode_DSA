class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       if(p.size() > s.size()) return {};
       vector<int> required(128, 0);
       vector<int> window(128, 0);
       for(char ch : p) ++required[ch - 'A'];
       int have = 0;
       vector<int> ans;
       int k = p.size();
       int requiredHave = 0;
for (int c = 0; c < 128; ++c)
    if (required[c] > 0) ++requiredHave;
       for(int right = 0; right< (int)s.size(); ++right){
            int ch = s[right] - 'A';
            if(++window[ch] == required[ch])
               ++have;
            if(right >= k){
                int evict = s[right - k] - 'A';
                if(--window[evict] == required[evict] - 1) --have;
            }
            if(right >= k - 1 && have == requiredHave){
                 ans.push_back(right - k + 1);
            }
       }
       return ans;
    }
};