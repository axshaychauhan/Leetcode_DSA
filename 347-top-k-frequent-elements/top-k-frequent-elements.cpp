class Solution {
public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;

    // (frequency, value) — frequency FIRST, because pair compares .first first,
    // so plain greater<> gives a min-heap BY FREQUENCY. No lambda, no decltype.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for (const auto& [value, count] : freq) {     // reference — no pair copies
        pq.push({count, value});                  // flipped at the door
        if ((int)pq.size() > k) pq.pop();         // cast — no sign-compare warning
    }

    vector<int> ans;
    ans.reserve(k);
    while (!pq.empty()) {
        ans.push_back(pq.top().second);           // flipped at the exit too
        pq.pop();
    }
    return ans;
}
};