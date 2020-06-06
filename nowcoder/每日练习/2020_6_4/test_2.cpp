/*
进制转换
https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述:
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
示例1
输入
复制
7 2
输出
复制
111
*/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int x, y;
    bool flag = true;
    
    while(cin >> x >> y)
    {
        string res;
        //如果为负数，则先改为正数，最后在前面放个负号就行 
        if(x < 0)
        {
            flag = false;
            x *= -1;
        }
        else if(x == 0)
            res += '0';
        
        //y进制就是先%y获取低位数据，然后/y取到下一位 
        while(x > 0)
        {
            int rear = x % y;
            //大于9的按16进制运算规则处理 
            if(rear > 9)
            {
                res += (rear - 10 + 'A');
            }
            else
            {
                res += (rear + '0');
            }
            
            x /= y;
        }
        
        //如果为负数则加负号 
        if(flag == false)
        {
            res.push_back('-');
        }
        
        //翻转字符串 
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    
    return 0;
}
