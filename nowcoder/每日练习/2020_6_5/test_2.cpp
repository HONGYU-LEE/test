/*
连续最大和
https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&&tqId=29858&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3 
*/

/*
思路1.动态规划
状态方程 dp[i] = max(dp[i - 1], 0) + data[i];

思路2
和动态规划一样，当和小于0时说明不可能为最大连续合，其中必定存在相减过程，所以重新计算，如果当前为和大于0，则直接加上当前数据。
当数据的值超过最大值时，说明这个就是新的最大连续子序列和 
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int count = 0;
    int size = 0;
        
    while(cin >> size)
    {
        vector<int> data(size);
        for(int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
        
        int max = data[0];
        for(int i = 0; i < size; i++)
        {
            if(count < 0)
            {
                count = data[i];
            }
            else
            {
                count += data[i];
            }
            
            if(count > max)
            {
                max = count;
            }
        }
        cout << max << endl;
    }
    
    return 0;
}

/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int count = 0;
    int size = 0;
        
    while(cin >> size)
    {
        vector<int> data(size);
        for(int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
        
        vector<int> dp(size);
        int res = data[0];
        dp[0] = data[0];
        
        for(size_t i = 1; i < data.size(); i++)
        {
            dp[i] = max(dp[i - 1], 0) + data[i];
            
            if(dp[i] > res)
            {
                res = dp[i];
            }
        }
        
        cout << res << endl;
    }
    
    return 0;
}
*/
