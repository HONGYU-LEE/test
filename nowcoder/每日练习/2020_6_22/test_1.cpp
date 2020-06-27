/*
反转字符串 
https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串
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

