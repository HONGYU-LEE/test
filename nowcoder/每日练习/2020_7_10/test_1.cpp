/*
链接：https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559
来源：牛客网
年会抽奖
今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
2. 待所有字条加入完毕，每人从箱中取一个字条；
3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？

*/
#include<iostream>
using namespace std;


//错排
double count(int n)
{
    if(n == 1)
    {
        return 0;
    }
    else if(n == 2)
    {
        return 1;
    }
    else
    {
        return (n - 1) * (count(n - 1) + count(n - 2));
    }
}

double factorial(int n)
{
    double res = 1;
    
    while(n > 1)
    {
        res *= n;
        n--;
    }
    return res;
}

int main()
{
    int num;
    while(cin >> num)
    {
        double res = count(num) / factorial(num) * 100;
        printf("%.2lf", res);
        cout << '%' << endl;
    }
    
    return 0;
}
