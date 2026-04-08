class Solution {
public:
    void dfs(int node, vector<vector<int>>& matrix, vector<bool>& visited) {
        visited[node] = true;

        for(int i = 0; i<matrix.size(); ++i) {
            if(matrix[node][i] == 1 && !visited[i])
                dfs(i, matrix, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n+1);
        int provinceCount = 0;
        for(int node = 0; node < n; ++node) {
            if(!visited[node]){
                dfs(node, isConnected, visited);
                ++provinceCount;
            }
        }
        return provinceCount;
    }
};