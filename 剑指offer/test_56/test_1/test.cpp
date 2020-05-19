class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int flag = 0;
        //使用一个标识位，与所有数据相与，因为其他数据都出现两次，异或结果位0，所以最后的flag就是x和y的异或结果，也就是他们不同的位

        for(int i = 0; i < nums.size(); i++)
        {
            flag ^= nums[i];
        }

        //我们只需要留下那两个数据不同的任何一个位，所以与自己的反码相与。与反码相与后留下来的就只有补码时进的那一位。也就是最后一个1的位置
        flag &= (-flag);

        int x = 0, y = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            //当这一位为1时，与x异或，为0时，与y异或，就可以将数据划分开。
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
