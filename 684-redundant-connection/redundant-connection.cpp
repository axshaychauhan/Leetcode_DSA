class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    bool unionMerge(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);

        if(parentU == parentV) return false; //cycle

        if(rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        }
        else if(rank[parentV] > rank[parentU]) {
            parent[parentU] = parentV;
        }
        else {
            parent[parentU] = parentV;
            rank[parentV]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1, 1);

        for(int i = 1; i<=n; ++i) parent[i] = i;

        for(const auto& edge: edges) {
            if(!unionMerge(edge[0], edge[1]))
                return edge;
        }

        return {};
    }
};