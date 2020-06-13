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
 �󹫹��������������
 ����������ʱ��������ڵ�һ���ȸ��ڵ��һ���ȸ��ڵ�С������ڵ����ǹ������ȡ�
 ������������˵����ֱ���ҵ����㼴��
 ����ͨ�Ķ��������������ڵ�һ��Ҫ�ڸ��ڵ����������һ��Ҫ�ڸ��ڵ����������
 */
class Solution {
public:
    bool Find(TreeNode* root, TreeNode* cur)
    {
        if(root == nullptr)
            return false;
        else if(root == cur)
            return true;

        return Find(root->left, cur) || Find(root->right, cur);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;

        //�������һ���ڵ�Ϊ���ڵ㣬��ô����������ȱض�Ϊ���ڵ�
        if(root == p || root == q)
            return root;

        //����p��q�ֱ����ĸ�������
        bool pInLeft = Find(root->left, p);
        bool pInRight = !pInLeft;
        bool qInLeft = Find(root->left, q);
        bool qInRight = !qInLeft;

        //���p��q�ֱ��ڸ��ڵ�����������ϣ�����ڵ�Ϊ�����������
        if((pInLeft && qInRight) || (pInRight && qInLeft))
            return root;
        //�����������ϣ������������������
        else if(pInLeft && qInLeft)
            return lowestCommonAncestor(root->left, p, q);
        //��������������������������������
        else if(qInRight && pInRight)
            return lowestCommonAncestor(root->right, p, q);

        //û�ҵ������ؿ�
        return nullptr;
    }
};
