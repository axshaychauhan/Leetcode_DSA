class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        };

        map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            pq(cmp);

        for (auto element : freq) {
            pq.push(element);
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};