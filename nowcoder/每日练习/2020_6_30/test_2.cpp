/*
������
https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
���������ߣ������ж�һ���ܲ������һ�������Ρ�
*/

#include<iostream>
using namespace std;

int main()
{
    double x, y, z;
    
    while(cin >> x >> y >> z)
    {
        if(x == 0 || y == 0 || z == 0)
        {
            cout << "No" << endl;
        }
        //�������������߼�����������ڵ�����
        else if((x + y <= z) || (x + z <= y) || (y + z <= x))
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}
