class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = 0, max = nums[0];

        for(const auto& i : nums)
        {
            //如果上一次和小于0, 说明其中必定有相减过程，子集和必定不为最大，所以重新开始计算
            if(count <= 0)
            {
                count = 0;
            }
            //加上当前数据
            count += i;

            //如果当前和超过最大值，则更新最大值
            if(count > max)
            {
                max = count;
            }
        }
    
        return max;
    }
};
