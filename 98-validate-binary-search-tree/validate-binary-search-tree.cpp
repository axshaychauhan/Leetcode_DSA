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
  void dfs(TreeNode* root, vector<int>& list) {
        if(!root)
           return;
        
        dfs(root->left, list);
        list.push_back(root->val);
        dfs(root->right, list);

    }
    bool isValidBST(TreeNode* root) {
        vector<int> list;
        dfs(root, list);
        for(int i = 0; i<list.size()-1; ++i) {
            if(list[i] >= list[i+1])
               return false;
        }
        return true;
    }
};