/*
链接：https://www.nowcoder.com/questionTerminal/3549ff22ae2c4da4890e9ad0ccb6150d
来源：牛客网
客似云来
NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天都过来；并且，所有人在这家店吃了两天早餐后，接下来每天都会带一位新朋友一起来品尝。
于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……
现在，NowCoder想请你帮忙统计一下，某一段时间范围那他总共卖出多少份早餐（假设每位客人只吃一份早餐）。
*/
//斐波那契区间和 
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int num1, num2;
    vector<long long> ret(81);
    ret[0] = 0;
    ret[1] = 1;

    for(size_t i = 2; i < 81; i++)
    {
        ret[i] = ret[i - 1] + ret[i - 2];
    }
    
    while(cin >> num1 >> num2)
    {
        long long sum = 0;
        
        for(size_t i = num1; i <= num2; i++)
        {
            sum += ret[i];
        }
        
        cout << sum << endl;
    }
}
