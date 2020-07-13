/*
淘宝网店
https://www.nowcoder.com/questionTerminal/754921e9c98b43d1b2d70c227b844101
NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
现在给你一段时间区间，请你帮他计算总收益有多少。
*/


//其实就是日期计算器 
#include<iostream>
using namespace std;

bool is_year(int year)
{
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int year1, month1, day1;
    int year2, month2, day2;
    int months[13] = {0, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2};
    int days[13] = {0, 31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};
    
    while(cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
    {
        int res = 0;
        //如果是不同年的，就直接一年一年加
        
        while(year1 < year2)
        {
            if(is_year(year1))
            {
                res += 580;
            }
            else
            {
                res += 579;
            }
            
            year1++;
        }
        
        //接着计算同年的
        //如果月份不同
        while(month1 < month2)
        {
            res += (months[month1] * days[month1]);
            month1++;
        }
        
        //此时月份相同，开始计算天数
        res += ((day2 - day1 + 1) * months[month2]);
        
        cout << res << endl;
    }
    
    return 0;
}
