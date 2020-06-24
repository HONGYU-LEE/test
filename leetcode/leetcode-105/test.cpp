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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inBegin, int inEnd) 
    {
        if(inBegin > inEnd)
            return nullptr;

        //ǰ��ĵ�һ���ڵ��������ĸ��ڵ�
        TreeNode* Inroot = new TreeNode(preorder[preIndex]);

        //ͨ�����ڵ���������������
        int rootIndex = inBegin;
        while(rootIndex <= inEnd)
        {
            if(inorder[rootIndex] == preorder[preIndex])
                break;
            else 
                rootIndex++;
        }

        //��ʱ�ҵ����ڵ��λ�ã����ڵ�����(inBegin, rootIndex - 1)�������������ұ�(rootIndex + 1, inEnd)������������
        //����������������ڷ�Χ����ݹ鹹�������ڷ�Χ��˵��û��������
        if(inBegin <= rootIndex -1)
            Inroot->left = _buildTree(preorder, inorder, ++preIndex, inBegin, rootIndex - 1);
        else 
            Inroot->left = nullptr;

        //����������
        if(rootIndex + 1 <= inEnd)
            Inroot->right = _buildTree(preorder, inorder, ++preIndex, rootIndex + 1, inEnd);
        else 
            Inroot->right = nullptr;

        return Inroot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preIndex = 0;
        int inBegin = 0, inEnd = inorder.size() - 1;

        return _buildTree(preorder, inorder, preIndex, inBegin, inEnd);
    }
};
