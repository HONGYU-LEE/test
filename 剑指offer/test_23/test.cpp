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
            
            //先判断两边是否有环，如果有环进入下一步 
            if(fast == slow)
            {
                ListNode* cur = pHead;
                
                //此时快慢指针指向同一个位置，再让另一个cur指针从头出发，当slow和他相遇时相遇处就是入环点 
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
