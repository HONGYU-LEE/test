/*
https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
删除公共字符
题目描述
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
输入描述:
每个测试输入包含2个字符串
输出描述:
输出删除后的字符串
示例1
输入
复制
They are students. 
aeiou
输出
复制
Thy r stdnts.
*/

/*
	建立哈希表，记录所有str2中字符出现过的次数，然后遍历str1，如果这个字符在str2出现过，则忽略 
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1, str2;
    while(getline(cin, str1) && getline(cin, str2))
    {
        //建立哈希表， 记录所有str2所有字符出现的次数
        int hash[256] = {0};
        
        for(size_t i = 0; i < str2.size(); i++)
        {
            //直接在对应ascii值的位置计数
            hash[str2[i]]++;
        }
        
        string res;
        for(size_t j = 0; j < str1.size(); j++)
        {
        	//如果没出现过则加入 
            if(!hash[str1[j]])
            {
                res += str1[j];
            }
        }
            
        cout << res << endl;
    }
    
    return 0;
}
