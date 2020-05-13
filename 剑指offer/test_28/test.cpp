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
    //���ж��������ƣ��Ա��෴��λ�ü���
    bool isSame(TreeNode* A, TreeNode* B)
    {
        if(!A && !B)
            return true;
        else if(!A || !B)
            return false;

        if(A->val != B->val)
            return false;
        
        return isSame(A->right, B->left) && isSame(A->left, B->right);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;

        return isSame(root->left, root->right);
    }
};
