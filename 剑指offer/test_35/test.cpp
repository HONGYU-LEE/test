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
    思路。
    1.首先复制链表中的每一个节点，并插在那个节点的后面，此时所有的结点的下一个位置就是拷贝出的结点。
    2.拷贝random域，因为所有节点的下一个位置都是拷贝出的结点，所以random结点的下一个位置就是拷贝的random节点，所以遍历拷贝random域
    3.将链表拆分开，获取拷贝的链表

*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        CloneList(head);
        return BreakList(head);
    }

    void CloneList(Node* head)
    {
        //首先复制链表
        Node* cur = head;

        while(cur)
        {
            Node* next = cur->next;
            Node* copy = new Node(cur->val);

            cur->next = copy;
            copy->next = next;

            cur = next;
        }

        //复制random节点
        cur = head;
        
        while(cur)
        {
            Node* copy = cur->next;

            if(cur->random)
                copy->random = cur->random->next;
                //因为原节点的下一个位置就是拷贝节点，所以random节点的下一个位置就是拷贝的random节点
            else
                copy->random = nullptr;

            cur = copy->next;
        }

    }

    //拆分两个链表
    Node* BreakList(Node* head)
    {
        Node* cur = head;
        Node* copyhead = nullptr;
        Node* copytail = nullptr;

        while(cur)
        {
            Node* copy = cur->next;
            Node* next = copy->next;

            //第一次进入时初始化
            if(!copytail)
            {
                copyhead = copytail = copy;
            }
            else
            {
                copytail->next = copy;
                copytail = copy;
                //尾插
            }

            cur->next = next;
            cur = next;
        }

        return copyhead;
    }
};
