class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<unordered_set<int>> prereq(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        // Calculate inDegree. Push inDegree == 0 into the Queue.
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();
            // The State Pass: When you pop node and loop through its
            // neighbors:Add node to prereqs[neighbor]. Take everything inside
            // prereqs[node] and insert it into prereqs[neighbor]. (Handing over
            // the notebook).
            for (auto neighbour : adjList[node]) {
                prereq[neighbour].insert(node);
                unordered_set<int> prevPreReq = prereq[node];
                prevPreReq.insert(node);
                prereq[neighbour].insert(prevPreReq.begin(), prevPreReq.end());
                // Decrement inDegree[neighbor]. If it hits 0, push to Queue.
                if (--inDegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        // The Queries: Once Kahn's finishes, just loop through the queries. For
        // query [u, v], just check if u is inside prereqs[v].
        vector<bool> ans;
        for (auto query : queries) {
            if (prereq[query[1]].find(query[0]) != prereq[query[1]].end())
                ans.push_back(true);
            else
                ans.push_back(false);
        }


        return ans;
    }
};