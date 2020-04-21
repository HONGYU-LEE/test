/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {      
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow)
            {
                ListNode* cur = pHead;
                
                while(1)
                {
                    if(slow == cur)
                    {
                        return cur;
                    }
                    else
                    {
                        slow = slow->next;
                        cur = cur->next;
                    }
                }
            }
        }
        
        return nullptr;
    }
};
