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
    int getDepth(TreeNode* root) {
        if(!root)
            return 0;

        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
            
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)   
            return true;
            
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);

        return abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
