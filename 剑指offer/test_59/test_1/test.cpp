class Solution {
public:
    /*
        ����һ��˫�˶��У����������ݱȵ�ǰԪ��Сʱ��˵������Ԫ�ز�����Ϊ���ֵ��ȥ��ȫ���ȵ�ǰԪ��С�ģ�ֻ���±�����ġ�
        ������Ԫ�رȵ�ǰԪ�ش�ʱ�����ܱ�֤���ֵ����ʱ��ǰԪ�ز�Ϊ��������ƶ�����β

        �����ʱ���������ƶ�����ײ��ڴ���ʱ��ȥ������

        ������һ��deque�������±귽����㣬Ȼ�����vecotr���������
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty())
            return {};

        deque<int> deq;
        vector<int> ret;

        //�Ƚ�������������
        for(int i = 0; i < k; i++)
        {
            //�������Ԫ�رȵ�ǰԪ��С��˵����������Ϊ���ֵ������
            while(!deq.empty() && nums[deq.back()] <= nums[i])
                deq.pop_back();

            //���
            deq.push_back(i);
        }

        for(int i = k; i < nums.size(); i++)
        {
            //��
            ret.push_back(nums[deq.front()]);

            while(!deq.empty() && nums[deq.back()] <= nums[i])
                deq.pop_back();

            //���������ڳ���ʱȥ������
            if(!deq.empty() && deq.front() <= (i - k))
                deq.pop_front();

            deq.push_back(i);
        }
        //������һ��Ԫ��
        ret.push_back(nums[deq.front()]);

        return ret;
    }
};
