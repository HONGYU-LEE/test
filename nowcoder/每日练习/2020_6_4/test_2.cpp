/*
����ת��
https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
��������:
����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
�������:
Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�
ʾ��1
����
����
7 2
���
����
111
*/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int x, y;
    bool flag = true;
    
    while(cin >> x >> y)
    {
        string res;
        //���Ϊ���������ȸ�Ϊ�����������ǰ��Ÿ����ž��� 
        if(x < 0)
        {
            flag = false;
            x *= -1;
        }
        else if(x == 0)
            res += '0';
        
        //y���ƾ�����%y��ȡ��λ���ݣ�Ȼ��/yȡ����һλ 
        while(x > 0)
        {
            int rear = x % y;
            //����9�İ�16������������� 
            if(rear > 9)
            {
                res += (rear - 10 + 'A');
            }
            else
            {
                res += (rear + '0');
            }
            
            x /= y;
        }
        
        //���Ϊ������Ӹ��� 
        if(flag == false)
        {
            res.push_back('-');
        }
        
        //��ת�ַ��� 
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    
    return 0;
}
