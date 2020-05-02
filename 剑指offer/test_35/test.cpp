/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
    ˼·��
    1.���ȸ��������е�ÿһ���ڵ㣬�������Ǹ��ڵ�ĺ��棬��ʱ���еĽ�����һ��λ�þ��ǿ������Ľ�㡣
    2.����random����Ϊ���нڵ����һ��λ�ö��ǿ������Ľ�㣬����random������һ��λ�þ��ǿ�����random�ڵ㣬���Ա�������random��
    3.�������ֿ�����ȡ����������

*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        CloneList(head);
        return BreakList(head);
    }

    void CloneList(Node* head)
    {
        //���ȸ�������
        Node* cur = head;

        while(cur)
        {
            Node* next = cur->next;
            Node* copy = new Node(cur->val);

            cur->next = copy;
            copy->next = next;

            cur = next;
        }

        //����random�ڵ�
        cur = head;
        
        while(cur)
        {
            Node* copy = cur->next;

            if(cur->random)
                copy->random = cur->random->next;
                //��Ϊԭ�ڵ����һ��λ�þ��ǿ����ڵ㣬����random�ڵ����һ��λ�þ��ǿ�����random�ڵ�
            else
                copy->random = nullptr;

            cur = copy->next;
        }

    }

    //�����������
    Node* BreakList(Node* head)
    {
        Node* cur = head;
        Node* copyhead = nullptr;
        Node* copytail = nullptr;

        while(cur)
        {
            Node* copy = cur->next;
            Node* next = copy->next;

            //��һ�ν���ʱ��ʼ��
            if(!copytail)
            {
                copyhead = copytail = copy;
            }
            else
            {
                copytail->next = copy;
                copytail = copy;
                //β��
            }

            cur->next = next;
            cur = next;
        }

        return copyhead;
    }
};
