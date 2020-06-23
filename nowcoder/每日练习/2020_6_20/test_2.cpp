/*
�ַ���ͨ���
https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?tpId=37&&tqId=21294&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
����ƥ��1���ַ�
���룺
ͨ������ʽ��
һ���ַ�����
�����
����ƥ��Ľ������ȷ���true���������false
*/

#include<iostream>
#include<algorithm>

using namespace std;

bool isTrue(string s1, string s2)
{
    if(s1.empty())
        return s2.empty();
    
    //���һ����ǰ�ַ�Ϊ*
    if(s1[0] == '*')
    {
        //��ʱ����ѡ��ƥ��N�λ���0��
        if(!s2.empty())
        {
            return isTrue(s1.substr(1), s2) 
                || isTrue(s1, s2.substr(1));
        }
        else
        {
            //��ʱs2�Ѿ�Ϊ�գ�����ֻ��ƥ��0��
            return isTrue(s1.substr(1), s2);
        }
    }
    else
    {
        //�����ǰ��һ���ַ���ͬ������Ϊͨ�����,��ƥ��һ��
        if(s1[0] == s2[0] ||(!s2.empty() && s1[0] == '?'))
        {
            return isTrue(s1.substr(1), s2.substr(1));
        }
        else
        {
            return false;
        }
    }
}

int main()
{
   string s1, s2;
    
    while(cin >> s1 >> s2)
    {
        if(isTrue(s1, s2) == true)
            cout << "true" << endl;
        else 
            cout << "false" << endl;
    }
}
