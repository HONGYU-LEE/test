/*
计算日期到天数转换
https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
根据输入的日期，计算是这一年的第几天。。
详细描述： 
输入某年某月某日，判断这一天是这一年的第几天？。
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int year, month, day;
    
    while(cin >> year >> month >> day)
    {
        int time = 0;
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
            days[2]++;
        
        for(int i = 1; i < month; i++)
        {
            time += days[i];
        }
        
        time += day;
        
        cout << time << endl;
    }
    
    return 0;
}
