/*
�����ַ���
https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
��Ŀ����
��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I
��������:
ÿ�������������1������������ I like beijing. �����������Ȳ�����100
�������:
�����������֮����ַ���,�Կո�ָ�
ʾ��1
����
����
I like beijing.
���
����
beijing. like I
*/ 

/*
	˼·:�ȷ�ת���壬�ٷ�תÿ������ 
*/ 

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str))
    {
        reverse(str.begin(), str.end());
        
        auto begin = str.begin();

        while(begin != str.end())
        {
            auto end = begin;
            
            while(end != str.end() && *end != ' ')
                end++;
            
            reverse(begin, end);
            
            if(end != str.end())
                begin = ++end;
            else
                begin = end;
        }
        
        cout << str << endl;
    }
    return 0;
}
