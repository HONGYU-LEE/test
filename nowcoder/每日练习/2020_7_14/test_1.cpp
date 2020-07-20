/*
字符串计数 
https://www.nowcoder.com/questionTerminal/f72adfe389b84da7a4986bde2a886ec3
求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。
*/

/*
因为阿拉伯字母每位能表示从a-z的字幕，也就是说每位能表示26个字母，可以将问题转换为26进制来解决 
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
