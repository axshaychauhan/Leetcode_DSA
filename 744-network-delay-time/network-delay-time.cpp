class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create adjacency list
        //create distance vector
        //create priority queue and push k in it
        //traverse priority queue take out top 
        //traverse neighbours of top 
        //if distance to reach top + neighbour to top < distance[top] update distance
        //keep doing this unless q empty
        //iterate distance ARRAY and return maximum distance


        vector<vector<pair<int,int>>> adjList(n+1);
        for(const auto& edge: times) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});


        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > distance[node]) continue;

            for(const auto& neighbour: adjList[node]) {
                int neighbourNode = neighbour.first;
                int neighbourDistance = neighbour.second;

                if(d + neighbourDistance < distance[neighbourNode]) {
                    distance[neighbourNode] = d + neighbourDistance;
                    pq.push({distance[neighbourNode], neighbourNode});
                }
            }
        }

        int minimumDelayTime = 0;
        for(int i = 1; i<= n; ++i) {
            if(distance[i] == INT_MAX) return -1;
            minimumDelayTime = max(minimumDelayTime, distance[i]);
        }
        return minimumDelayTime;
    }
};