/*
��ת�ַ��� 
https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ���
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string str;
    
    while(cin >> str)
    {
       size_t begin = 0, end = str.size() - 1;
        
       while(begin < end)
       {
           swap(str[begin], str[end]);
           begin++, end--;
       }
        
       cout << str << endl; 
    }
    
    return 0;
}

