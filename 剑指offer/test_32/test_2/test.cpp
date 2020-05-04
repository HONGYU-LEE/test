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
    //��������ı��֣���Ҫ�ֲ��ӡ��������Ҫ���ö�άvector�Ͷ���
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
            //��ǰ���д�С���ǵ�ǰ���нڵ���������ǰ������нڵ㶼����level�У�Ȼ��ÿ������ٷ���ret
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
