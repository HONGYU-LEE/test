/*
幸运的袋子
https://www.nowcoder.com/practice/a5190a7c3ec045ce9273beebdfe029ee?tpId=85&&tqId=29839&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getLuckyPacket(vector<int>& balls, size_t pos, int sum, int multi)
{
    int count = 0;
    
    for(size_t i = pos; i < balls.size(); i++)
    {
        //计算乘积与累加和
        sum += balls[i];
        multi *= balls[i];
        
        //满足条件，记录当前组合，并且继续向后搜索看看是否满足
        if(sum > multi)
        {
            count += (1 + getLuckyPacket(balls, i + 1, sum, multi));
        }
        //乘积与和相等，则说明还有可能满足条件，继续往下搜索即可
        else if(sum == multi)
        {
            count += getLuckyPacket(balls, i + 1, sum, multi);
        }
        //不满足条件，sum < multi，并且乘积只会越来越大，不可能满足，所以中断
        else
        {
            break;
        }
        
        //回溯到原来的状态，继续搜索下一个组合
        sum -= balls[i];
        multi /= balls[i];
        
        //去重，碰到重复元素则直接跳过
        while(i < balls.size() - 1 && balls[i] == balls[i + 1])
        {
            i++;
        }
    }
    
    return count;
}

int main()
{
    int n; 
    
    while(cin >> n)
    {
        vector<int> balls(n);
        
        for(int i = 0; i < n; i++)
        {
            cin >> balls[i];
        }
        
        //排序 
        sort(balls.begin(), balls.end());
        
        cout << getLuckyPacket(balls, 0, 0, 1) << endl;
    }
    
    return 0;
}
