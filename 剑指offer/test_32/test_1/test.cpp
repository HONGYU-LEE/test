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
    //层序遍历，借助队列完成
    vector<int> levelOrder(TreeNode* root) {
        if(!root)
            return {};

        queue<TreeNode*> q;
        vector<int> ret;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* cur = q.front();
            ret.push_back(cur->val);
            q.pop();

            if(cur->left)
            {
                q.push(cur->left);
            }

            if(cur->right)
            {
                q.push(cur->right);
            }
        }

        return ret;
    }
};
