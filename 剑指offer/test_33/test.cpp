class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() <= 1)
            return true;

        int length = postorder.size() - 1;
        int root = postorder[length];
        //后序遍历的最后一个结点为根节点

        int i = 0;
        vector<int> leftTree;
        for(; i < length; ++i)
        {
            if(postorder[i] > root)
                break;

            leftTree.push_back(postorder[i]);
        }
        //找到所有比根节点小的节点，那些节点是二叉搜索树的左子树部分

        int j = i;
        vector<int> rightTree;
        for(; j < length; ++j)
        {
            if(postorder[j] < root)
                return false;

            rightTree.push_back(postorder[j]);
        }
        //找到所有右子树部分，[i, length]之间的是右子树部分，右子树部分的每一个节点都应该比root大，如果有比root节点小的则说明二叉搜索树不成立

        
        //递归判断左右子树
        bool left = true;
        if(i > 0)
            left = verifyPostorder(leftTree);
        
        bool right = true;
        if(i < length)
            right = verifyPostorder(rightTree);

        return (left && right);
        //需要左右子树都成立


    }
};
