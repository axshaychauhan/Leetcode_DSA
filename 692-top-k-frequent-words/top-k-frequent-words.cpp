class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };

        unordered_map<string, int> freq;
        for (string& word : words) {
            freq[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       decltype(cmp)>
            pq(cmp);

        for (auto& [word, count] : freq) {
            pq.push({count, word});
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;
        while (!pq.empty()) {
            auto& [count, word] = pq.top();
            ans.push_back(word);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};