/*
字符串通配符
https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?tpId=37&&tqId=21294&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符
输入：
通配符表达式；
一组字符串。
输出：
返回匹配的结果，正确输出true，错误输出false
*/

#include<iostream>
#include<algorithm>

using namespace std;

bool isTrue(string s1, string s2)
{
    if(s1.empty())
        return s2.empty();
    
    //情况一，当前字符为*
    if(s1[0] == '*')
    {
        //此时可以选择匹配N次或者0次
        if(!s2.empty())
        {
            return isTrue(s1.substr(1), s2) 
                || isTrue(s1, s2.substr(1));
        }
        else
        {
            //此时s2已经为空，所以只能匹配0次
            return isTrue(s1.substr(1), s2);
        }
    }
    else
    {
        //如果当前第一个字符相同，或者为通配符？,则匹配一个
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
