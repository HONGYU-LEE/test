class Solution {
public:
    /*
        借助一个双端队列，当队中数据比当前元素小时，说明队中元素不可能为最大值，去掉全部比当前元素小的，只留下比他大的。
        当队中元素比当前元素大时，不能保证最大值出队时当前元素不为最大，所以移动到队尾

        如果此时滑动窗口移动后队首不在窗口时，去掉队首

        借助了一个deque来保存下标方便计算，然后借助vecotr来存放数据
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty())
            return {};

        deque<int> deq;
        vector<int> ret;

        //先将滑动窗口填满
        for(int i = 0; i < k; i++)
        {
            //如果队中元素比当前元素小，说明它不可能为最大值，出队
            while(!deq.empty() && nums[deq.back()] <= nums[i])
                deq.pop_back();

            //入队
            deq.push_back(i);
        }

        for(int i = k; i < nums.size(); i++)
        {
            //将
            ret.push_back(nums[deq.front()]);

            while(!deq.empty() && nums[deq.back()] <= nums[i])
                deq.pop_back();

            //当滑动窗口超出时去掉队首
            if(!deq.empty() && deq.front() <= (i - k))
                deq.pop_front();

            deq.push_back(i);
        }
        //添加最后一个元素
        ret.push_back(nums[deq.front()]);

        return ret;
    }
};
