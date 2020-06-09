class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = begin;
        while(begin < end)
        {
            mid = ((end - begin) >> 1) + begin;
            if(nums[mid] < nums[end])
            {
                end = mid;
            }
            //����м���ұ�С����˵����Сֵ��ǰ�벿��
            else if(nums[mid] > nums[end])
            {
                begin = mid + 1;
            }
            //����м���ұߴ���˵����Сֵ�ں�벿��
            else
            {
                --end;
            }
            //����м���ұ���ȣ�˵���޷��жϴ�ʱ��λ�ã��������ұ�һ��������С��������������
        }

        return nums[end];
    }
};{\rtf1}
