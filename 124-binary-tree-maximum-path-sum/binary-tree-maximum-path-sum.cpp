/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxPath = INT_MIN;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int leftSubTree = max(0, dfs(root->left));
        int rightSubTree = max(0, dfs(root->right));

        int currMax = leftSubTree + rightSubTree + root->val;

        maxPath = max(maxPath, currMax);

        return max(leftSubTree, rightSubTree) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxPath;
    }
};