/*
求最小公倍数
https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
*/
/*
暴力求解，直接从最小的那个数开始遍历到他俩的乘积即可 
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
