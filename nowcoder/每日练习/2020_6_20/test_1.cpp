/*
ͳ��ÿ�������ӵ�����
https://www.nowcoder.com/practice/1221ec77125d4370833fd3ad5ba72395?tpId=37&&tqId=21260&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�
*/

#include<iostream>

using namespace std;
//쳲���������
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
