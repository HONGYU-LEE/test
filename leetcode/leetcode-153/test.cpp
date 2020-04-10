class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin < end)
        {
            int mid = ((end - begin) >> 1) + begin;
            if(nums[mid] < nums[end])
            {
                end = mid;
            }
            //����м���ұ�С����˵����Сֵ��ǰ�벿��
            else
            {
                begin = mid + 1;
            }
            //����м���ұߴ���˵����Сֵ�ں�벿��
        }

        return nums[end];
    }
};
