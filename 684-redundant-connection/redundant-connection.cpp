class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {
        if(node == parent[node]){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    bool unionFind(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if(rootU == rootV) {
            return false;
        }

        if(rank[rootU] > rank[rootV]){
            parent[rootV] = rootU;
        }
        else if(rank[rootU] < rank[rootV]){
            parent[rootU] = rootV;
        }
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1, 1);

        for(int i = 1; i<=n; ++i) {
            parent[i] = i;
        }

        for(auto edge: edges) {
            if(!unionFind(edge[0], edge[1]))
                return edge;
        }
        return {};
    }
};