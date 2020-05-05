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
        层序遍历的变种,奇数层顺序打印,逆序打印。这道题有三种思路
        1.双端队列deque,奇数层顺序插入，偶数层逆序插入，效率高
        2.和层序的queue解法一样，偶数层reverse反转，效率不高
        3.借用两个stack,一个存奇数层一个存偶数层,效率高
        这里使用的是双栈实现
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        {
            return {};
        }

        stack<TreeNode*> odd;
        stack<TreeNode*> even;
        //奇数栈和偶数栈
        vector<vector<int>> ret;

        odd.push(root);
        int flag = 1;

        while(!odd.empty() || !even.empty())
        {
            vector<int> level;
            //当层数为奇数时将奇数层的结点的子节点按照从左往右放入偶数栈
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
             //当层数为偶数时将偶数层的结点的子节点按照从右往左放入奇数栈
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
