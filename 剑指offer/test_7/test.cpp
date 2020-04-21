/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return nullptr;
        
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int pre_begin, int pre_end, vector<int>& inorder, int in_begin, int in_end)
    {
        TreeNode* root = new TreeNode(preorder[pre_begin]);
        root->left = nullptr;
        root->right = nullptr;

        int pos = in_begin;
        while(pos <= in_end && preorder[pre_begin] != inorder[pos])
        {
            ++pos;
        }

        int left_length = pos - in_begin;
        int right_length = in_end - pos;

        if(left_length > 0)
        {
            root->left = build(preorder, pre_begin + 1, pre_begin + left_length, inorder, in_begin, in_begin + left_length - 1);
        }
        if(right_length > 0)
        {
            root->right = build(preorder, pre_begin + left_length + 1, pre_end, inorder, in_begin + left_length + 1, in_end);
        }

        return root;
    }
};
