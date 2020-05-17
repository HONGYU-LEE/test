class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            Boyer-Moore ͶƱ������Ϊ����Ԫ��Ҳ���������������������г��ִ����������ݣ����Կ��Կ���ʹ��ͶƱ��
            ��ʽ��������������ͬһ��������Ʊ����һ����ͬ����ʱƱ����һ��Ʊ������ʱ������һ�����ݣ�������Ϊ������
            ������࣬Ʊ��Ҳ����࣬ͶƱ�Ľ��ֻ����������
        */
        int count = 1;
        int res = nums[0];

        for(int i = 1; i < nums.size(); ++i)
        {
            //Ʊ��Ϊ����Ϊ��һ������ͶƱ
            if(!count)
            {
                count = 1;
                res = nums[i];
            }
            //������ͬ��Ʊ����һ
            else if(nums[i] == res)a
            {
                ++count;
            }
            //���ݲ�ͬƱ����һ
            else
            {
                --count;
            }
        }

        return res;
    }
};
