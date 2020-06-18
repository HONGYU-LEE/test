/*
参数解析
https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677?tpId=37&&tqId=21297&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
在命令行输入如下命令：
xcopy /s c:\ d:\，
各个参数如下： 
参数1：命令字xcopy 
参数2：字符串/s
参数3：字符串c:\
参数4: 字符串d:\
请编写一个参数解析程序，实现将命令行各个参数解析出来。
解析规则： 
1.参数分隔符为空格 
2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy /s “C:\program files” “d:\”时，参数仍然是4个，第3个参数应该是字符串C:\program files，而不是C:\program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
3.参数不定长 
4.输入由用例保证，不会出现不符合要求的输入 
*/

/*
每次读取一个单词放进vector里,如果当前碰到双引号，则遍历完双引号中的内容
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string str;

    while(getline(cin, str))
    {
        int count = 0;
        vector<string> res;
        
        auto start = str.begin();
        
        string temp;
        while(start != str.end())
        {
            if(*start == '"')
            {
                do
                {
                    temp += *start;
                    start++;
                }while(*start != '"');
                    
                temp.push_back(*start);
            }
            else if(*start != ' ')
            {
                temp += *start;
            }
            else
            {
                count++;
                res.push_back(temp);
                temp.clear();
            }
            
            start++;
        }
        count++;
        res.push_back(temp);
        
        cout << count << endl;
        
        for(const auto& i : res)
        {
            cout << i << endl;
        }
    }
    
    return 0;
}
