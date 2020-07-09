/*
链接：https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
来源：牛客网

一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，即包含2和3两个因子。NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。
*/
// write your code here cpp
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//题目没描述清楚，应该是求质因子


int main()
{
    int num;
    
    while(cin >> num)
    {
        int count = 0;
        for(size_t i = 2; i <= sqrt(num); i++)
        {
            if(num % i == 0)
            {
                count++;
                //短除法分解
                while(num % i == 0)
                {
                    num /= i;
                }
            }
        }
        
        //最后结果中还有一个
        if(num != 1)
        {
            count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
