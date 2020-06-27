/*
公共字符串计算 
https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&&tqId=21298&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
计算两个字符串的最大公共字串的长度，字符不区分大小写
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1, s2;
    
    while(cin >> s1 >> s2)
    {
        if(s1 > s2)
        {
            s1.swap(s2);
        }
        
        string temp;
        int max = 0;
        int count = 0;
        size_t i = 0;
        while(i < s1.size())
        {
            if(temp.empty() || s2.find(temp) != string::npos)
            {
                temp += s1[i++];
                count++;
            }
            else
            {
                temp.erase(temp.begin());
                count--;
            }
            
            if(s2.find(temp) != string::npos && count > max)
            {
                max = count;
            }
        }
        
        cout << max << endl;
    }
    
    return 0;
}
