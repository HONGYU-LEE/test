/*
Fibonacci����
https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85&&tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i-1] + F[i-2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
*/
#include<iostream>
using namespace std;

int main()
{
    int prev = 0, cur = 1, next = 1;
    int num;
    while(cin >> num)
    {
        int x = 0, y = 0;
        
        while(num > next)
        {
            prev = cur;
            cur = next;
            next = prev + cur;
            
            x = next - num;
            y = num - cur;
        }
        
        int res = x > y ? y : x;
        
        cout << res << endl;
    }
    
    return 0;
}
