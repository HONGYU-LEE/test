/*
�ַ������� 
https://www.nowcoder.com/questionTerminal/f72adfe389b84da7a4986bde2a886ec3
���ֵ�����s1��s2֮��ģ�������len1��len2���ַ����ĸ��������mod 1000007��
*/

/*
��Ϊ��������ĸÿλ�ܱ�ʾ��a-z����Ļ��Ҳ����˵ÿλ�ܱ�ʾ26����ĸ�����Խ�����ת��Ϊ26��������� 
*/

#include<string>
#include<iostream>

using namespace std;

int func(string str)
{
    int ret = 0;
    for(size_t i = 0; i < str.size(); i++)
    {
        ret = 26 * ret + (str[i] - 'a');
    }
    
    return ret;
}

int main()
{
    string s1, s2;
    int len1, len2;
    
    while(cin >> s1 >> s2 >> len1 >> len2)
    {
        cout << ((func(s2) - func(s1) - 1) % 1000007) << endl;
    }
    
    return 0;
}
