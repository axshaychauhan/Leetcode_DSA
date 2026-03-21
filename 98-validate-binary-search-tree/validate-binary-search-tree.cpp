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
  void dfs(TreeNode* root,long& prevNodeVal, bool& isValid) {
        if(!root)
           return;
        
        dfs(root->left, prevNodeVal, isValid);
        if(root->val <= prevNodeVal) isValid = false;
        prevNodeVal = root->val;
        dfs(root->right, prevNodeVal, isValid);

    }
    
    bool isValidBST(TreeNode* root) {
        bool isValid {true};
        long prevMinNode = LONG_MIN;
        dfs(root, prevMinNode, isValid);
        return isValid;
       
    }
};