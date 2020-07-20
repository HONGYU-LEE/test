/*
链接：https://www.nowcoder.com/questionTerminal/9ae56e5bdf4f480387df781671db5172
来源：牛客网
最长公共子序列
我们有两个字符串m和n，如果它们的子串a和b内容相同，则称a和b是m和n的公共子序列。子串中的字符不一定在原字符串中连续。
例如字符串“abcfbc”和“abfcab”，其中“abc”同时出现在两个字符串中，因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。
现在给你两个任意字符串（不包含空格），请帮忙计算它们的最长公共子序列的长度。
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s1, s2;
    
    while(cin >> s1 >> s2)
    {
        //用矩阵来存储中间值(i, j)代表当字符串a遍历到i，字符串b遍历到j时的最长公共子序列
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
        
        //处理边界
        dp[0][0] = (s1[0] == s2[0]) ? 1 : 0;
        
        for(size_t i = 1; i < s1.size(); i++)
        {
            dp[i][0] = (s1[i] == s2[0]) ? 1 : 0;
            dp[i][0] = max(dp[i][0], dp[i - 1][0]);
        }
        
        for(size_t i = 1; i < s2.size(); i++)
        {
            dp[0][i] = (s1[0] == s2[i]) ? 1 : 0;
            dp[0][i] = max(dp[0][i], dp[0][i - 1]);
        }
        
        for(size_t i = 1; i < s1.size(); i++)
        {
            for(size_t j = 1; j < s2.size(); j++)
            {
                //选出最长的
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                
                //如果当前两者刚好匹配，则比较(i, j)和(i - 1, j - 1)
                if(s1[i] == s2[j])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        
        cout << dp[s1.size() - 1][s2.size() - 1] << endl;
    }
    
    return 0;
}
