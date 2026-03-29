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
   unordered_map<int, int> index;
   void createMapOfIndex(vector<int> inorder, unordered_map<int, int>& mp) {
            for(int i = 0; i< inorder.size(); ++i) {
                mp[inorder[i]] = i;
            }
   }

   TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preOrderStart, int preOrderEnd, int inOrderStart, int inOrderEnd) {
            if(preOrderStart > preOrderEnd || inOrderStart > inOrderEnd) {
                return nullptr;
            }

            int rootVal = preorder[preOrderStart];
            TreeNode* node = new TreeNode(rootVal);
            int rootIndex = index[rootVal];
            int leftPart = rootIndex - inOrderStart;

            node->left = solve(preorder, inorder,preOrderStart + 1, preOrderStart + leftPart, inOrderStart, rootIndex - 1);
            node->right = solve(preorder, inorder, preOrderStart + leftPart + 1, preOrderEnd, rootIndex + 1, inOrderEnd);

            return node;
   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //create map if indorder and index
        //first element of preorder would be root of tree
        //find that element in inorder
        //left part from that element would become leftsubtree and right part would become right subtree
        //now next element from preorder becomes root
        // solve this problems until preorder elements are finsihed or inorderStart > inorderEnd;

        createMapOfIndex(inorder, index);
   return solve(preorder, inorder, 0, preorder.size()-1, 0 , inorder.size() - 1);

    }
};