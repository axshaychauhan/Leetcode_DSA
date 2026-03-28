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
    TreeNode* findMinInRightSubTree(TreeNode*& root) {
        if(!root->left)
           return root;

        return findMinInRightSubTree(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(root-> val == key) {
            if(!root->left)
               return root->right;
            if(!root->right)
               return root->left;
            
            TreeNode* replacement = findMinInRightSubTree(root->right);
            root->val = replacement->val;
            root->right  = deleteNode(root->right, replacement->val);
            return root;
        }

        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};