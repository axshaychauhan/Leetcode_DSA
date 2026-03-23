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
        void lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
            if(root->val == p->val || root->val == q->val) {
               ans = root;
               return;
            }

            if(root->val < p->val )
               lca(root->right, p, q, ans);
            else if(root->val > q->val)
               lca(root->left, p, q, ans);
            else {
               ans = root; return;
            }
            
        }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  

        TreeNode* ans = NULL;
        if(p->val < q ->val) {
             lca(root, p, q, ans);
        }
        else {
             lca(root, q, p, ans);
        }

        return ans;
    }
};