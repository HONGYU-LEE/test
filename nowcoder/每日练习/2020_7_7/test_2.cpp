// write your code here cpp
/*
��������
https://www.nowcoder.com/questionTerminal/1046cd038f7a4b04b2b77b415973de1c
һ�黨������������Щͼ��������һ��ֱ�ӿ��õ�С����������Ҳ��һЩͼ�������ڸ����Ļ�������С����������һ���ܴӻ������о����ܼ�������С�������أ�
*/
/*
�ж��Ӵ����ֵĴ��� 
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1, str2;
    
    while(cin >> str1 >> str2)
    {
        int count = 0;
        size_t i = 0;
        for(size_t i = 0; i < str1.size(); i++)
        {
            if(str1[i] == str2[0])
            {
                size_t temp = i + 1, j = 1;
                
                for(; j < str2.size(); j++)
                {
                    if(str1[temp] == str2[j])
                    {
                        temp++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(j == str2.size())
                {
                    count++;
                    i = temp - 1;
                }
            }
        }
        cout << count << endl;
    }
    
    return 0;
}
