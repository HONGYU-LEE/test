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
    /*
        ������Ҫ֪�����������������ʣ����ӱȸýڵ�С���Һ��ӱȸýڵ��
        ��ʹ������������ȱ������ӣ��ٱ������ڵ㣬�������Һ���
        �Ǵ�С�����˳��
        ���Ҫ���ص�k��ģ�����Ҫ�Ӵ�С�����Կ��Ըı�һ������������ĳ��ȱ����Һ��ӣ��ٱ������ӡ�������k�����Ƿ���ֵ
    */
    int count = 0;
    int res;

    int kthLargest(TreeNode* root, int k) {
        PrevTravel(root, k);        
        return res;
    }

    void PrevTravel(TreeNode* root, int k)
    {
        if(!root)
            return;

        PrevTravel(root->right, k);

        if(++count == k)
            res = root->val;

        PrevTravel(root->left, k);
    }
};
