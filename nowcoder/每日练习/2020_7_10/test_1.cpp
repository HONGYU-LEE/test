/*
���ӣ�https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559
��Դ��ţ����
���齱
���깫˾���Ľ�Ʒ�ر���������񽱵Ĺ��ȴ�����⣺
1. ���ȣ�������Ա����һ��д���Լ����ֵ���������齱���У�
2. ����������������ϣ�ÿ�˴�����ȡһ��������
3. ����鵽��������д�ľ����Լ������֣���ô����ϲ�㣬�н��ˣ���
���ڸ�����μ�������������������ж��ٸ��ʻ�������˻񽱣�

*/
#include<iostream>
using namespace std;


//����
double count(int n)
{
    if(n == 1)
    {
        return 0;
    }
    else if(n == 2)
    {
        return 1;
    }
    else
    {
        return (n - 1) * (count(n - 1) + count(n - 2));
    }
}

double factorial(int n)
{
    double res = 1;
    
    while(n > 1)
    {
        res *= n;
        n--;
    }
    return res;
}

int main()
{
    int num;
    while(cin >> num)
    {
        double res = count(num) / factorial(num) * 100;
        printf("%.2lf", res);
        cout << '%' << endl;
    }
    
    return 0;
}
