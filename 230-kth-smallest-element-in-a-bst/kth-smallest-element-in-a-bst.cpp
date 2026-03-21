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
    void dfs(TreeNode* root, int& count, int& kthVal){
        if(!root)
           return;
        
        dfs(root->left, count, kthVal);
        --count;
        if(count == 0) kthVal = root->val;
        dfs(root->right,count, kthVal);

        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
           return 0;
        int kthVal = 0;
         dfs(root, k, kthVal);
         return kthVal;
    }
};