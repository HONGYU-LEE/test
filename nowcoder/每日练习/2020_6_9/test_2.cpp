/*
����С������
https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
*/
/*
������⣬ֱ�Ӵ���С���Ǹ�����ʼ�����������ĳ˻����� 
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int max, min;
    
    while(cin >> max >> min)
    {
        if(max < min)
        {
            swap(max, min);
        }
        
        for(size_t i = max ; i <= max * min; i++)
        {
            if(i % max == 0 && i % min == 0)
            {
                cout << i << endl;
                break;
            }
        }
    }
    
    return 0;
}
