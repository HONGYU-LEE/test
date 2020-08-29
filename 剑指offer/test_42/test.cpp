class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = 0, max = nums[0];

        for(const auto& i : nums)
        {
            //�����һ�κ�С��0, ˵�����бض���������̣��Ӽ��ͱض���Ϊ����������¿�ʼ����
            if(count <= 0)
            {
                count = 0;
            }
            //���ϵ�ǰ����
            count += i;

            //�����ǰ�ͳ������ֵ����������ֵ
            if(count > max)
            {
                max = count;
            }
        }
    
        return max;
    }
};
