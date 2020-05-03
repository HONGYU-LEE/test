/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) 
    {
        Node* tail = nullptr;
        InorderTravel(root, tail);
        //ͨ��β���������
        Node* head = tail;

        while(head && head->left)
            head = head->left;

        //�ҵ�����ڵ㣬Ҳ������������ĵ�һ���ڵ㣬������ͷ��㣬���䷵��

        if(head)
        {                 
            head->left = tail;
            tail->right = head;
        }
        //��ͷβ�ڵ���������Ϊ����ͽ�ָoffer��һ�����ĳ���ѭ������

        return head;
    }
    
    /*
        ���������һ�����ָ��ǰ�ڵ㣬һ�����ָ����һ���ڵ�
        ��Ϊ��Ҫת����˫������������Ҫ����ǰ�������ڵ�
    */
    void InorderTravel(Node* cur, Node*& Pre)
    {
        /*
            �����������Ϊ��������������ڵ�ȸ��ڵ�С���ҽڵ�ȸ��ڵ������ֻ��Ҫ���������
            ������Ҫת��Ϊ˫������������Ҫ�����нڵ�ǰ����������
            InorderTravel(cur->left, Pre);
            Pre = cur;
            InorderTravel(cur->right, Pre);
        */
        if(!cur)
            return;

        if(cur->left)
            InorderTravel(cur->left, Pre);
        //����������

        cur->left = Pre;
        //��ǰ�ڵ������һ���ڵ�

        if(Pre)
            Pre->right = cur;
        //�����һ���ڵ���ڣ�����һ���ڵ����ӵ���ǰ�ڵ�

        Pre = cur;
        //�������ڵ�

        if(cur->right)
            InorderTravel(cur->right, Pre);
        //����������
    }

    
};
