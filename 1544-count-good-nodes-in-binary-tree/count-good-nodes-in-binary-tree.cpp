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
    void dfs(TreeNode* root, int maximumSofar, int& goodCount) {
        if(!root)
           return;

        if(root->val >= maximumSofar) {
           ++goodCount;
           maximumSofar = root->val;
        }

        dfs(root->left, maximumSofar, goodCount);
        dfs(root->right, maximumSofar, goodCount);

        return;
    }
    int goodNodes(TreeNode* root) {
        int goodCount = 0;

        dfs(root, root->val, goodCount);

        return goodCount;
    }
};