class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            rank.resize(n, 1);
            parent.resize(n);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = find(parent[node]);
        }

        bool unionMerge(int u, int v) {
            int parentU = find(u);
            int parentV = find(v);

            if (parentU == parentV)
                return false;

            if (rank[parentU] > rank[parentV]) {
                parent[parentV] = parentU;
            } else if (rank[parentV] > rank[parentU]) {
                parent[parentU] = parentV;
            } else {
                parent[parentV] = parentU;
                rank[parentU]++;
            }

            return true;
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);

        // map emails to account ids
        unordered_map<string, int> emailAccountIds;

        for (int i = 0; i <n; ++ i) {
            for (int j = 1; j < accounts[i].size(); ++j) {

                string email = accounts[i][j];
                if (emailAccountIds.find(email) == emailAccountIds.end()) {
                    emailAccountIds[email] = i;
                } else {
                    dsu.unionMerge(i, emailAccountIds[email]);
                }
            }
        }

        // merge emails of same account

        unordered_map<int, vector<string>> mergedEmailAccount;
        for (auto emailAccount : emailAccountIds) {
            string email = emailAccount.first;
            int emailIndex = emailAccount.second;

            int rootIndex = dsu.find(emailIndex);
            mergedEmailAccount[rootIndex].push_back(email);
        }
        // create answer after converting account ids to name

        vector<vector<string>> ans;

        for (auto pair : mergedEmailAccount) {
            int rootIndex = pair.first;
            vector<string> emails = pair.second;

            // email should be sorted
            sort(emails.begin(), emails.end());

            vector<string> finalAccount;
            finalAccount.push_back(accounts[rootIndex][0]); // Push the Name
            finalAccount.insert(finalAccount.end(), emails.begin(), emails.end()); // Push sorted emails
            ans.push_back(finalAccount);
        }

        return ans;
    }
};