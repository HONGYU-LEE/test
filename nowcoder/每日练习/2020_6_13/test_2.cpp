/*
�������һ��ż����ӽ�����������
https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С��������
*/
#include<iostream>
#include<cmath>

using namespace std;

//�ж�����
bool isNum(int num)
{
    int i  = 2;
    for(i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
            return false;
    }
    
    if(i > sqrt(num))
        return true;
    else
        return false;
}

int main()
{
    int num;
    
    while(cin >> num)
    {
        //���м俪ʼ�������ң�������߶�Ϊ������˵������ӽ��ģ�ֱ�����
        int mid = num / 2;
        int x = mid, y = mid;
        
        for(int i = mid; i > 0; i--)
        {
            x = i;
            y = num - i;
            
            if(isNum(x) && isNum(y))
                break;
        }
        
        cout << x << endl;
        cout << y << endl;
    }
}
