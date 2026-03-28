/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createParentMap(TreeNode*  root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(!root)
           return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i<size; ++i) {
                TreeNode* node = q.front(); q.pop();
                if(node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if(node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        createParentMap(root, parent);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int distance = 0;

        while(!q.empty()) {
            if(distance++ == k)
               break;

            int size = q.size();

            for(int i = 0; i<size; ++i) {
                TreeNode* node = q.front(); q.pop();
                if(node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        vector<int> nodes;
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            nodes.push_back(node->val);
        }
        return nodes;

    }
};