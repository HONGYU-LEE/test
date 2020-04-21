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
            
            //���ж������Ƿ��л�������л�������һ�� 
            if(fast == slow)
            {
                ListNode* cur = pHead;
                
                //��ʱ����ָ��ָ��ͬһ��λ�ã�������һ��curָ���ͷ��������slow��������ʱ�����������뻷�� 
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
