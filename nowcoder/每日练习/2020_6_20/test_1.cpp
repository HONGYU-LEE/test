/*
统计每个月兔子的总数
https://www.nowcoder.com/practice/1221ec77125d4370833fd3ad5ba72395?tpId=37&&tqId=21260&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？
*/

#include<iostream>

using namespace std;
//斐波那契数列
int main()
{
    int num;
    
    while(cin >> num)
    {
        int prev = 1, cur = 1, next = 2;
        if(num < 3)
            cout << "1" << endl;
       
        for(size_t i = 3; i < num; i++)
        {
            prev = cur;
            cur = next;
            
            next = prev + cur;
        }
        
        cout << next << endl;
    }
    return 0;
}
