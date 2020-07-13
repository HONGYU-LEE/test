/*
�Ա�����
https://www.nowcoder.com/questionTerminal/754921e9c98b43d1b2d70c227b844101
NowCoder���Ա��Ͽ���һ�����ꡣ���������·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
���ڸ���һ��ʱ�����䣬������������������ж��١�
*/


//��ʵ�������ڼ����� 
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
        //����ǲ�ͬ��ģ���ֱ��һ��һ���
        
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
        
        //���ż���ͬ���
        //����·ݲ�ͬ
        while(month1 < month2)
        {
            res += (months[month1] * days[month1]);
            month1++;
        }
        
        //��ʱ�·���ͬ����ʼ��������
        res += ((day2 - day1 + 1) * months[month2]);
        
        cout << res << endl;
    }
    
    return 0;
}
