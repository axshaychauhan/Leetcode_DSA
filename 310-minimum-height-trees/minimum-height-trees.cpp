class Solution {
public:
    // Handle the base case: If n == 1, just return [0].

    // Build the vector<unordered_set<int>> adjList (Using a set makes it really
    // fast to remove edges later).

    // Build a vector<int> degree array that counts how many edges each node
    // has.

    // Push every node where degree[i] == 1 into a queue<int> leaves.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};

        vector<unordered_set<int>> adjList(n);
        vector<int> degree(n, 0);

        for (auto edge : edges) {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);

            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> leaves;
        for (int i = 0; i < degree.size(); ++i) {
            if (degree[i] == 1)
                leaves.push(i);
        }

        //     Track Remaining Nodes: Create a variable int remainingNodes = n;.
        int remainingNode = n;

        // The Loop Condition: We keep peeling while (remainingNodes > 2).
        // (Remember, a tree can only have 1 or 2 centers!).
        while (remainingNode > 2) {

            // Level-Order BFS: * Take a snapshot of the queue size (int sz =
            // leaves.size();).

            int sz = leaves.size();

            // Subtract sz from remainingNodes immediately (we are about to rip
            // these leaves off).
            remainingNode -= sz;
            // Loop sz times to process the current layer.
            for (int i = 0; i < sz; ++i) {
                // The Snapping Logic (Inside the level loop):

                // Pop a leaf from the queue.
                int leaf = leaves.front();
                leaves.pop();

                // Look at that leaf's adjList to find its neighbor (since it's
                // a leaf, there will only be exactly 1 neighbor).
                int neighbour = *adjList[leaf].begin();

                // The Crucial Step: Go to the neighbor's adjList and erase()
                // the leaf from it.
                adjList[neighbour].erase(leaf);

                // Decrement the degree of that neighbor.
                //push it into queue if degree becomes 1 (new leaf node)
                if (--degree[neighbour] == 1) {
                    leaves.push(neighbour);
                }
            }
        }

        vector<int> ans;
        while(!leaves.empty()) {
            ans.push_back(leaves.front());
            leaves.pop();
        }

        return ans;
    }
};