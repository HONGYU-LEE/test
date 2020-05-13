class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() <= 1)
            return true;

        int length = postorder.size() - 1;
        int root = postorder[length];
        //������������һ�����Ϊ���ڵ�

        int i = 0;
        vector<int> leftTree;
        for(; i < length; ++i)
        {
            if(postorder[i] > root)
                break;

            leftTree.push_back(postorder[i]);
        }
        //�ҵ����бȸ��ڵ�С�Ľڵ㣬��Щ�ڵ��Ƕ���������������������

        int j = i;
        vector<int> rightTree;
        for(; j < length; ++j)
        {
            if(postorder[j] < root)
                return false;

            rightTree.push_back(postorder[j]);
        }
        //�ҵ��������������֣�[i, length]֮��������������֣����������ֵ�ÿһ���ڵ㶼Ӧ�ñ�root������б�root�ڵ�С����˵������������������

        
        //�ݹ��ж���������
        bool left = true;
        if(i > 0)
            left = verifyPostorder(leftTree);
        
        bool right = true;
        if(i < length)
            right = verifyPostorder(rightTree);

        return (left && right);
        //��Ҫ��������������


    }
};
