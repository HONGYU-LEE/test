/*
���ӣ�https://www.nowcoder.com/questionTerminal/9ae56e5bdf4f480387df781671db5172
��Դ��ţ����
�����������
�����������ַ���m��n��������ǵ��Ӵ�a��b������ͬ�����a��b��m��n�Ĺ��������С��Ӵ��е��ַ���һ����ԭ�ַ�����������
�����ַ�����abcfbc���͡�abfcab�������С�abc��ͬʱ�����������ַ����У���ˡ�abc�������ǵĹ��������С����⣬��ab������af���ȶ������ǵ��ִ���
���ڸ������������ַ������������ո񣩣����æ�������ǵ�����������еĳ��ȡ�
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
        //�þ������洢�м�ֵ(i, j)�����ַ���a������i���ַ���b������jʱ�������������
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
        
        //����߽�
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
                //ѡ�����
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                
                //�����ǰ���߸պ�ƥ�䣬��Ƚ�(i, j)��(i - 1, j - 1)
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
