/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 ����������ʱ��������ڵ�һ���ȸ��ڵ��һ���ȸ��ڵ�С������ڵ����ǹ������ȡ�
 ������ȸ��ڵ����˵�������������ϡ������ȸ��ڵ�С����˵�������������ϡ� 
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        else if(p == root || q == root)
            return root;

        if((root->val > p->val && root->val < q->val) || (root->val > q->val && root->val < p->val))
            return root;
        else if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p ,q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        return nullptr;
    }
};
