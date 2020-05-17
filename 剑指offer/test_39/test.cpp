class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            Boyer-Moore 投票法，因为多数元素也就是众数，是整个数组中出现次数最多的数据，所以可以考虑使用投票的
            方式来计数，当出现同一个数据是票数加一，不同数据时票数减一，票数归零时换成下一个数据，这样因为众数的
            次数最多，票数也就最多，投票的结果只能是众数。
        */
        int count = 1;
        int res = nums[0];

        for(int i = 1; i < nums.size(); ++i)
        {
            //票数为零则为下一个数据投票
            if(!count)
            {
                count = 1;
                res = nums[i];
            }
            //数据相同，票数加一
            else if(nums[i] == res)a
            {
                ++count;
            }
            //数据不同票数减一
            else
            {
                --count;
            }
        }

        return res;
    }
};
