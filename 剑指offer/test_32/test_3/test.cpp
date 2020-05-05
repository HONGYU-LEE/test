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
        ��������ı���,������˳���ӡ,�����ӡ�������������˼·
        1.˫�˶���deque,������˳����룬ż����������룬Ч�ʸ�
        2.�Ͳ����queue�ⷨһ����ż����reverse��ת��Ч�ʲ���
        3.��������stack,һ����������һ����ż����,Ч�ʸ�
        ����ʹ�õ���˫ջʵ��
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        {
            return {};
        }

        stack<TreeNode*> odd;
        stack<TreeNode*> even;
        //����ջ��ż��ջ
        vector<vector<int>> ret;

        odd.push(root);
        int flag = 1;

        while(!odd.empty() || !even.empty())
        {
            vector<int> level;
            //������Ϊ����ʱ��������Ľ����ӽڵ㰴�մ������ҷ���ż��ջ
            if(flag & 1)
            {
                while(!odd.empty())
                {
                    TreeNode* cur = odd.top();
                    odd.pop();
                    level.push_back(cur->val);

                    if(cur->left)
                        even.push(cur->left);

                    if(cur->right)
                        even.push(cur->right);
                }
            }
             //������Ϊż��ʱ��ż����Ľ����ӽڵ㰴�մ��������������ջ
            else
            {
               while(!even.empty())
                {
                    TreeNode* cur = even.top();
                    even.pop();
                    level.push_back(cur->val);

                    if(cur->right)
                        odd.push(cur->right);

                    if(cur->left)
                        odd.push(cur->left);
                }
            }
            
            ++flag;
            ret.push_back(level);
        }
        return ret;    
    }
};
