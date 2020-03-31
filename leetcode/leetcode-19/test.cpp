class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=1;
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
            len++;
        }
        if(n==len) return head->next;  //如果是第一个，则直接返回head->next;
        int m=len-n-1;                 //倒数第n个，就是从头开始第len-n+1个，但是我们要保存他的前一个数字，并且数字是从1开始的；这里减了一个2
        ListNode* pre=head,* now=head->next;
        while(m>0){
            pre=pre->next;
            now=now->next;
            m--;
        }
        pre->next=now->next;
        return head;
    }
