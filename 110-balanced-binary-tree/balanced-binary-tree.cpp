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
    int height(TreeNode* root, int& balanced) {
        if(!root) return 0;
        if(!balanced) return 0;

        int left = height(root->left, balanced);
        int right = height(root->right, balanced);
        
        if(abs(left - right) > 1)         balanced = false;


        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        int bal = true;
        height(root, bal);
        return bal;

        

    }
};