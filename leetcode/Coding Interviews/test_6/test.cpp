/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<ListNode*> s;
        vector<int> vec;

        ListNode* cur = head;

        while(cur != nullptr)
        {
            s.push(cur);
            cur = cur->next;
        }

        while(!s.empty())
        {
            ListNode* node = s.top();
            vec.push_back(node->val);
            s.pop();
        }
        
        return vec;
    }
};
