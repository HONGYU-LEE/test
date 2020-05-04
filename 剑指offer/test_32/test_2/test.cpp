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
    //层序遍历的变种，需要分层打印，所以需要借用二维vector和队列
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        q.push(root);

        while(!q.empty())
        {
            
            int levelsize = q.size();
            vector<int> level;
            //当前队列大小就是当前层中节点数，将当前层的所有节点都放入level中，然后每层结束再放入ret
            while(levelsize--)
            {
                TreeNode* cur = q.front();
                q.pop();
                level.push_back(cur->val);

                if(cur->left)
                {
                    q.push(cur->left);
                }

                if(cur->right)
                {
                    q.push(cur->right);
                }
            }
            ret.push_back(level);
        }
        return ret;
    }
};
