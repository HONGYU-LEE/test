/*
倒置字符串
https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
题目描述
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
输入描述:
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
输出描述:
依次输出倒置之后的字符串,以空格分割
示例1
输入
复制
I like beijing.
输出
复制
beijing. like I
*/ 

/*
	思路:先反转整体，再反转每个单词 
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
