class Solution {
public:
    bool isSame(TreeNode* A, TreeNode* B)
    {
        if(!B)
            return true;
        else if(!A)
            return false;
        //判断条件和子树不一样，如果B先遍历完则说明是，A先遍历完则说明不是子结构

        if(A->val != B->val)
            return false;

        return isSame(A->left, B->left) && isSame(A->right, B->right);
    }


    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B || !A)
            return false;
        //如果当前节点A或B为空，则说明不是子结构
        //如果相等则说明是

        if(isSame(A, B))
            return true;

        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
