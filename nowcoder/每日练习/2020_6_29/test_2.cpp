/*
�쵽������
https://www.nowcoder.com/questionTerminal/82424d93369649b98720743c25edc6ce
С���Ǻ�ϲ�����Լ�װ��������ģ������룩������Ҫ������ܳ������������̣����Ǿͽ���ȥ�ˡ�

���ڸ��������ǵ���������İ뾶�����ж�һ���ܷ�����ȥ��
*/


/*
�����ܳ����жϼ��� 
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    double s1, s2;
    
    while(cin >> s1 >> s2)
    {
        double perimeter = s2 * 2 * 3.14;
        
        if(s1 < perimeter)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
