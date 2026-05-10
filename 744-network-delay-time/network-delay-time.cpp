class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n+1);
        vector<int> dist(n+1, INT_MAX);

        for(auto& edge: times) {
            adjList[edge[0]].push_back({edge[1],edge[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            auto [d, node] = pq.top(); 
            pq.pop();

            if(d > dist[node]) continue;

            for(auto& neighbour: adjList[node]) {
                int neigh = neighbour.first;
                int time = neighbour.second;

                if(d + time < dist[neigh]) {
                    dist[neigh] = d + time;
                    pq.push({d + time , neigh});
                }

            }
        }

        int minimumTime = 0;

        for(int i = 1; i<=n; ++i) {
            if(dist[i] == INT_MAX) return -1;
            minimumTime = max(minimumTime, dist[i]);
        }

        return minimumTime;
    }
};