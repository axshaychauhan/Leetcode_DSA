class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> inDegree(numCourses, 0);

        for (auto preq : prerequisites) {
            int course = preq[0];
            int prerequisite = preq[1];

            adjList[prerequisite].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        int coursesTaken = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {

                int course = q.front();
                q.pop();
                ++coursesTaken;

                auto neighbours = adjList[course];
                for (int neighbour : neighbours) {
                    if (--inDegree[neighbour] == 0)
                        q.push(neighbour);
                }
            }
        }

        return coursesTaken == numCourses;
    }
};