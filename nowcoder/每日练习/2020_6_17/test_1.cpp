/*
完全数计算
https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84?tpId=37&&tqId=21279&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。

它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。

例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。

给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000

返回n以内完全数的个数。 异常情况返回-1
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//找出所有除了本身以外的约数
void getDivNum(int num, vector<int>& divNum)
{
    for(int i = 1; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            divNum.push_back(i);
            
            if((num / i != i) && (num / i != num))
                divNum.push_back(num / i);
        }
    }
}

int main()
{
    int num;
    
    while(cin >> num)
    {
        vector<int> divNum;
        int count = 0;
        
        for(int i = 2; i <= num; i++)
        {
            divNum.clear();
            getDivNum(i, divNum);
            
            //判断约数和是否等于本身
            int sum = 0;
            for(size_t i = 0; i < divNum.size(); i++)
            {
                sum += divNum[i];
            }
            
            if(sum == i)
                count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
