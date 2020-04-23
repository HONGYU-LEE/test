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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        
        ListNode* Head = new ListNode();
        ListNode* cur = Head;

        while(l1 && l2)
        {
            //ȡ������С�Ĳ���
            if(l1->val > l2->val)
            {
                cur->next = l2;
                l2 = l2->next;
            }
            else
            {
                cur->next = l1;
                l1 = l1->next;
            }

            cur = cur->next;
        }
        
        //�������ʣ��û�����������ȥ
        if(l1)
        {
            cur->next = l1;
        }

        if(l2)
        {
            cur->next = l2;
        }

        return Head->next;
    }
};
