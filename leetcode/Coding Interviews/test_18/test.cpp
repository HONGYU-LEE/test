class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* cur = newhead;

        while(cur && cur->next)
        {
            if(cur->next->val == val)
            {
                cur->next = cur->next->next;
                break;
            }
            else
            {
                cur = cur->next;
            }
        }

        return newhead->next;
    }
};
