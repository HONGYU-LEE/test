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
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& postIndex, int inBegin, int inEnd) 
    {
        if(inBegin > inEnd)
            return nullptr;

        int rootIndex = inEnd;
        TreeNode* root = new TreeNode(postorder[postIndex]);

        //���ݺ�������ĸ��ڵ���������������
        while(rootIndex >= inBegin)
        {
            if(postorder[postIndex] == inorder[rootIndex])
                break;
            else 
                rootIndex--;
        }

        //������Ϊ(inBegin, rootIndex - 1) ������(rootIndex + 1, inEnd)

        //����������
        if(rootIndex + 1 <= inEnd)
            root->right = _buildTree(inorder, postorder, --postIndex, rootIndex + 1, inEnd);
        else 
            root->right = nullptr;
            
        //����������
        if(inBegin <= rootIndex - 1)
            root->left = _buildTree(inorder, postorder, --postIndex, inBegin, rootIndex - 1);
        else 
            root->left = nullptr;


        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int postIndex = postorder.size() - 1;
        int inBegin = 0, inEnd = inorder.size() - 1;

        return _buildTree(inorder, postorder, postIndex, inBegin, inEnd);
    }
};
