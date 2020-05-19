class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int flag = 0;
        //ʹ��һ����ʶλ���������������룬��Ϊ�������ݶ��������Σ������λ0����������flag����x��y���������Ҳ�������ǲ�ͬ��λ

        for(int i = 0; i < nums.size(); i++)
        {
            flag ^= nums[i];
        }

        //����ֻ��Ҫ�������������ݲ�ͬ���κ�һ��λ���������Լ��ķ������롣�뷴��������������ľ�ֻ�в���ʱ������һλ��Ҳ�������һ��1��λ��
        flag &= (-flag);

        int x = 0, y = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            //����һλΪ1ʱ����x���Ϊ0ʱ����y��򣬾Ϳ��Խ����ݻ��ֿ���
            if(nums[i] & flag)
            {
                x ^= nums[i];
            }
            else
            {
                y ^= nums[i];
            }
        }

        return {x, y};
    }
};
