class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //create bidirectional weighted adjList of equations
        //traverse queries
        //check if src and destinations are present in adjList else store -1 in results
        //check if src == dst insert 1 in results
        //run bfs engine by inserting src
        //use unordered set for visited to avoid cycles
        //traverse all neighbours using bfs and keep multiplying product
        //if found make flag true
        //after exhausting bfs check if found true return results

        unordered_map<string, vector<pair<string, double>>> adjList;
        for(int i = 0; i<equations.size(); ++i) {
            string numerator = equations[i][0];
            string denominator = equations[i][1];

            double weight = values[i];

            adjList[numerator].push_back({denominator, weight});
            adjList[denominator].push_back({numerator,1/weight}); //added reverse edge
        }

        vector<double> results;
        

        for(auto& edge : queries) {
            string src = edge[0];
            string dst = edge[1];

            if(adjList.find(src) == adjList.end() || adjList.find(dst) == adjList.end()) {
                results.push_back(-1.0);
                continue;
            }

            if(src == dst) {
                results.push_back(1.0);
                continue;
            }

            queue<pair<string, double>> q;
            unordered_set<string> visited;

            q.push({src, 1.0});
            visited.insert(src);
            bool found {false};

            while(!q.empty()) {
                auto[currentNode, currentWeight]  = q.front();
                q.pop();

                if(currentNode == dst) {
                    found = true;
                    results.push_back(currentWeight);
                    break;
                }

                for(auto& neighbour: adjList[currentNode]) {
                    string edge = neighbour.first;
                    double edgeWeight = neighbour.second;

                    if(visited.find(edge) == visited.end()){
                        visited.insert(edge);
                        q.push({edge, edgeWeight * currentWeight});
                    }
                }
            }

            if(!found){
                results.push_back(-1.0);
            }
        }
    return results;
    }
};