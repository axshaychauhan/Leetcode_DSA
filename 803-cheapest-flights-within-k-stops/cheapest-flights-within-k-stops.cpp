class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //create adjList [[airport,price]]
        vector<vector<pair<int,int>>> adjList(n);
        for(auto route: flights) {
            adjList[route[0]].push_back({route[1], route[2]});
        }

        //create vector to store minimum cost to reach citys
        vector<int> minimumCost(n, INT_MAX);

        //create queue which will store [currentStopCount, city, cost]
        queue<tuple<int,int,int>> q;

        //push src in queue
        q.push({0, src, 0});

        //do bfs on queue
        while(!q.empty()) {
            auto [stops, node, currCost] = q.front();
            q.pop();

            if(stops > k) continue;
            for(auto neighbour: adjList[node]) {
               int city = neighbour.first;
               int price = neighbour.second;

               if(currCost + price < minimumCost[city]) {
                minimumCost[city] = currCost + price;
                q.push({stops + 1, city, currCost + price});
               }
            }
        }

        return minimumCost[dst] == INT_MAX ? -1 : minimumCost[dst];

    }
};