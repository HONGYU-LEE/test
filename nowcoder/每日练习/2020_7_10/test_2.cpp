/*
链接：https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800
来源：牛客网
抄送列表
NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。他认为这些抄送的邮件重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，优先处理重要的邮件。
现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str))
    {
        size_t pos = 0;
        vector<string> res;
        
        while(pos < str.size())
        {
            //如果出现"，则去匹配下一个"
            if(str[pos] == '\"')
            {
                size_t end = str.find('\"', pos + 1);
                
                //这里为了后面方便比较，不存入""
                res.push_back(str.substr(pos + 1, end - pos - 1));
                
                //跳过,和"
                pos = end + 2;
            }
            else
            {
                //如果没有出现，则直接匹配姓名    
                size_t end = str.find(',', pos + 1);
                if(end == string::npos)
                {
                    //此时说明后面没有， 是最后一个姓名，直接加入
                    
                    res.push_back(str.substr(pos, str.size() - pos));
                    break;
                }
                
                
                res.push_back(str.substr(pos, end - pos));
                
                //跳过,
                pos = end + 1;
            }
        }
        
        string name;
        getline(cin, name);
        
        if(find(res.begin(), res.end(), name) != res.end())
        {
            cout << "Ignore" << endl;
        }
        else
        {
            cout << "Important!" << endl;
        }
        
    }
    return 0;
}
