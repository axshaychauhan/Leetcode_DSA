class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> inDegree(numCourses, 0);

        for (auto& preq : prerequisites) {
            int course = preq[0];
            int prereqCourse = preq[1];

            adjList[prereqCourse].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;

        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> courseOrder;
        int courseTaken = 0;
        while (!q.empty()) {

            int course = q.front();
            q.pop();
            ++courseTaken;
            courseOrder.push_back(course);

            for (auto& neighbour : adjList[course]) {
                if (--inDegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        if(courseTaken == numCourses)
            return courseOrder;
        return {};
    }
};