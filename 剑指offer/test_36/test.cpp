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
        //通过尾结点来遍历
        Node* head = tail;

        while(head && head->left)
            head = head->left;

        //找到最左节点，也就是中序遍历的第一个节点，他就是头结点，将其返回

        if(head)
        {                 
            head->left = tail;
            tail->right = head;
        }
        //将头尾节点相连，因为这里和剑指offer不一样，改成了循环链表

        return head;
    }
    
    /*
        中序遍历，一个结点指向当前节点，一个结点指向上一个节点
        因为需要转换成双向链表，所以需要连接前后两个节点
    */
    void InorderTravel(Node* cur, Node*& Pre)
    {
        /*
            中序遍历，因为二叉搜索树的左节点比根节点小，右节点比根节点大，所以只需要中序遍历。
            但又需要转换为双向链表，所以需要把所有节点前后连接起来
            InorderTravel(cur->left, Pre);
            Pre = cur;
            InorderTravel(cur->right, Pre);
        */
        if(!cur)
            return;

        if(cur->left)
            InorderTravel(cur->left, Pre);
        //遍历左子树

        cur->left = Pre;
        //当前节点接上上一个节点

        if(Pre)
            Pre->right = cur;
        //如果上一个节点存在，则上一个节点连接到当前节点

        Pre = cur;
        //遍历根节点

        if(cur->right)
            InorderTravel(cur->right, Pre);
        //遍历右子树
    }

    
};
