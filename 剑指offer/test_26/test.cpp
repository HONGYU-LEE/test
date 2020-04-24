class Solution {
public:
    bool isSame(TreeNode* A, TreeNode* B)
    {
        if(!B)
            return true;
        else if(!A)
            return false;
        //�ж�������������һ�������B�ȱ�������˵���ǣ�A�ȱ�������˵�������ӽṹ

        if(A->val != B->val)
            return false;

        return isSame(A->left, B->left) && isSame(A->right, B->right);
    }


    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B || !A)
            return false;
        //�����ǰ�ڵ�A��BΪ�գ���˵�������ӽṹ
        //��������˵����

        if(isSame(A, B))
            return true;

        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
