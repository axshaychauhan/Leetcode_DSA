class Solution {
public:
    using P = pair<int, pair<int, int>>;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P, vector<P>> pq;
        for (auto& point : points) {
            int x = point[0], y = point[1];
            int d = x * x + y * y;

            pq.push({d, {x, y}});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto& data = pq.top();
            ans.push_back({data.second.first, data.second.second});
            pq.pop();
        }

        return ans;
    }
};