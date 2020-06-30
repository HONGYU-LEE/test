/*
计算字符串的距离
https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&&tqId=21275&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
、Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。

Ex：

字符串A:abcdefg

字符串B: abcdef

通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。

要求：

给定任意两个字符串，写出一个算法计算它们的编辑距离。 
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
    动态规划
    f(i , j)表示字符串s1前i个元素转换到s2前i个元素的编辑距离
    
    状态方程min(f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + (w1[i]==w2[j]?0:1))
*/

int minDistance(string s1, string s2)
{
    //如果某一个为空，则编辑距离为另一个字符串的长度
    if(s1.empty() || s2.empty())
    {
        return s1.empty() ? s2.size() : s1.size();
    }
    
    //多给一点防止越界
    vector<vector<int>> distance(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    
    //处理边界
    for(size_t i = 0; i <= s1.size(); i++)
    {
        distance[i][0] = i;
    }
    
    for(size_t i = 0; i <= s2.size(); i++)
    {
        distance[0][i] = i;
    }
    
    for(size_t i = 1; i <= s1.size(); i++)
    {
        for(size_t j = 1; j <= s2.size(); j++)
        {
            //当前最短编辑距离可能是从s1变换也可能是s2变换一步过来，选取最短的
            distance[i][j] = 1 + min(distance[i - 1][j], distance[i][j - 1]);
            if(s1[i - 1] == s2[j - 1])
            {
                //如果当前字符相等，则说明distance(i - 1, j - 1)不用变换
                distance[i][j] = min(distance[i][j], distance[i - 1][j - 1]);
            }
            else
            {
                //如果不同，则需要distance(i - 1, j - 1)变换一步到达
                distance[i][j] = min(distance[i][j], 1 + distance[i - 1][j - 1]);
            }
        }
    }
    
    return distance[s1.size()][s2.size()];
}

int main()
{
    string s1, s2;
    
    while(cin >> s1 >>s2)
    {
        cout << minDistance(s1, s2) << endl;
    }
    return 0;
}
