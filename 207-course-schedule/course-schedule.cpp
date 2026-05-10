class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(const auto& edge: prerequisites) {
            adjList[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int> q;
        for(int i = 0; i<numCourses; ++i) {
            if(inDegree[i] == 0) q.push(i);
        }

        int courseTaken = 0;
        while(!q.empty()) {
            int course = q.front();
            q.pop();

            ++courseTaken;

            for(auto& neighbour: adjList[course]){
                if(--inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        return numCourses == courseTaken;
    }
};