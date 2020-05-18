class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        //�����ÿһ��λ��1�����������г��ֹ��Ĵ�����Ȼ��%3,�Ϳ���ȥ�����������ε�Ԫ�أ��ҵ�ֻ����һ�ε�Ԫ��
        for(int i = 0; i < 32; i++)
        {
            int count = 0;

            for(int j = 0; j < nums.size(); j++)
            {
                //�����ǰ���ݵĵ�iλΪ1��������һ
                if((nums[j] >> i) & 1)
                {
                    count++;
                }
            }
            //ȥ�����������ε�����
            count %= 3;
            //����iλ�Ľ���Ž�res��
            res |= (count << i);
        }

        return res;
    }
};
