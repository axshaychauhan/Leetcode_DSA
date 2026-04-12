class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //create adjacency list
        //create distance vector
        //push source in queue as <stop,node,cost>
        //traverse queue for nearest stops
        //if stops > k continue
        //check if current_cost + cost of next flight < distance[node] if yes update it
        vector<vector<pair<int, int>>> adjList(n);
        for(auto& flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }
        // vector<vector<pair<int, int>>> adjList(n);
        // for(const auto& flight: flights)
        //     adjList[flights[0]].push_back({flights[1], flights[2]});

        vector<int> dist(n, INT_MAX);

        queue<tuple<int,int,int>> q;

        q.push({0, src, 0});
        dist[src] = 0;

        while(!q.empty()){

            int stop = get<0>(q.front());
            int node = get<1>(q.front());
            int cost = get<2>(q.front());
            q.pop();

            if(stop > k) continue;
            for(auto& edge:adjList[node]){
                int neighbour = edge.first;
                int price = edge.second;

                if(cost + price < dist[neighbour]){
                    dist[neighbour] = cost + price;
                    q.push({stop+1, neighbour, cost + price});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};