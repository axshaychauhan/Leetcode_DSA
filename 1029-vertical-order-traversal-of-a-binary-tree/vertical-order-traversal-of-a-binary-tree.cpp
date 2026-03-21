/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
           return {};

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> mpIndexValues;
  
        while(!q.empty()) {
            auto[node, rowColIndex] = q.front();
            q.pop();

            mpIndexValues[rowColIndex.first][rowColIndex.second].insert(node->val);

            if(node->left)
               q.push({node->left, {rowColIndex.first - 1,rowColIndex.second + 1 }});
            if(node->right)
               q.push({node->right,{rowColIndex.first + 1,rowColIndex.second + 1 }});

        }

    vector<vector<int>> ans;

for(auto col : mpIndexValues) {
    vector<int> currentColumnNodes;
    for(auto row : col.second) {
        currentColumnNodes.insert(currentColumnNodes.end(), row.second.begin(), row.second.end());
    }
    ans.push_back(currentColumnNodes);
    }
    return ans;
    }
};