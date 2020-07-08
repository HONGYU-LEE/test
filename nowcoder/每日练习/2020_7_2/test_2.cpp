/*
有假币
链接：https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
来源：牛客网

居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，结果找来的零钱中有假币！！！可惜nowcoder 一不小心把它混进了一堆真币里面去了。只知道假币的重量比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。

*/
// write your code here cpp
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int num;
    
    while(cin >> num)
    {
        if(num == 0)
            break;
        
        int count = 0, sum = 1;
        
        //每次需要分为3组，两组对比，一组观察，如果两组中出现一组有假币，则继续判断那一组，如果都没有则是观察的那组。
        while(num > 1)
        {
            //能刚好整除就直接除
            if(num % 3 == 0)
                num /= 3;
            //不能整除就向上取整
            else
                num = num / 3 + 1;
            count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
