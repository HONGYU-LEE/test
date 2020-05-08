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
        首先需要知道搜索二叉树的性质，左孩子比该节点小，右孩子比该节点大
        而使用中序遍历则先遍历左孩子，再遍历根节点，最后遍历右孩子
        是从小到大的顺序。
        如果要返回第k大的，则需要从大到小，所以可以改变一下中序遍历，改成先遍历右孩子，再遍历左孩子。这样第k个则是返回值
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
