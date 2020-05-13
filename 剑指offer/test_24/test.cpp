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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;

        ListNode* newHead = nullptr;
        ListNode* cur = head;

        while(cur)
        {
            ListNode* next = cur->next;

            cur->next = newHead;
            newHead = cur;
            
            cur = next;
        }
        //ͷ�巨

        return newHead;
    }
};
