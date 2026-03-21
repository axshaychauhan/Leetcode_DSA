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
    int dfs(TreeNode* root, int& count) {
        if(!root)
           return 0;

        int left = dfs(root->left, count);
        if(left != 0) return left;

        if(--count == 0) return root->val;

        return dfs(root->right, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root,k);
    }
};