class Solution {
public:
    /*
      有点类似于滑动窗口，当和大于目标时，移动small,去掉序列中的最小值
      当和小于目标时，移动big,往序列中增加一个最大值,保证能获取所有序列。
    */
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> temp;

        
        int small = 1, big = 2;
        int mid = (target + 1) / 2;
        int count = small + big;
        //连续子序列的最大值只能为序列的中间值，所以当small等于mid时说明已遍历完

        while(small < mid)
        {
            //如果和目标相同，则将数据保存
            if(count == target)
            {
                temp = addNum(small, big);
                res.emplace_back(temp);
            }

            //如果当前和大于目标，small小于mid，说明还没遍历完，此时子序列元素数量过多，去掉最小值。
            while(count > target && small < mid)
            {
                count -= small;
                small++;

                if(count == target)
                {
                    temp = addNum(small, big);
                    res.emplace_back(temp);
                }
            }

            //增加数据进序列中
            big++;
            count += big;
        }
    
        return res;
    }

    vector<int> addNum(int small, int big)
    {
        vector<int> temp;
        //将区间的值添加进数组中
        //emplace效率比push高，少了临时数据的构建
        for(int i = small; i <= big; i++)
        {
            temp.emplace_back(i);
        }

        return temp;
    }
};
