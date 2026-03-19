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
    int dfs(TreeNode* root, bool& isBalanced) {
        if(!root)
           return 0;
           
        if(!isBalanced)
           return 0;

        int leftHeight = dfs(root->left, isBalanced);
        int rightHeight = dfs(root->right, isBalanced);

        if(abs(leftHeight - rightHeight) > 1)
           isBalanced = false;
        
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        dfs(root, isBalanced);
        return isBalanced;
    }
};