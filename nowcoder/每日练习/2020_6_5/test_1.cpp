/*
ͳ�ƻ���
https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId=85&&tqId=29842&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ��������ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B���������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
���磺
A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
* �ڵ�һ����ĸ��a��֮��: "abba" �ǻ���
* ����ĸ��b��֮��: "abba" �ǻ���
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
�������������Ĵ�Ϊ2 
*/

//˼·��ֱ�ӱ����ⷨ���ֱ���ÿһ��λ�ò����ַ�����Ȼ���ж��Ƿ�Ϊ���ĺ�������� 
 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isReverse(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    
    return temp == str;
}
int main()
{
    string s1, s2;
    
    while(getline(cin, s1) && getline(cin, s2))
    {
        int count = 0;
        
        for(size_t i = 0; i <= s1.size(); i++)
        {
            string temp = s1;
            temp.insert(i, s2);
            
            if(isReverse(temp) == true)
                count++;
        }
        
        cout << count << endl;
    }
    return 0;
}
