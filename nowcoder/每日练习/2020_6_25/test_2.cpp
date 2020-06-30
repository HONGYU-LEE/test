/*
�����ַ����ľ���
https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&&tqId=21275&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
��Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭������������ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ����༭������㷨�������ɶ����ѧ��Levenshtein����ģ����ֽ�Levenshtein Distance��

Ex��

�ַ���A:abcdefg

�ַ���B: abcdef

ͨ�����ӻ���ɾ���ַ���g���ķ�ʽ�ﵽĿ�ġ������ַ�������Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��롣

Ҫ��

�������������ַ�����д��һ���㷨�������ǵı༭���롣 
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
    ��̬�滮
    f(i , j)��ʾ�ַ���s1ǰi��Ԫ��ת����s2ǰi��Ԫ�صı༭����
    
    ״̬����min(f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + (w1[i]==w2[j]?0:1))
*/

int minDistance(string s1, string s2)
{
    //���ĳһ��Ϊ�գ���༭����Ϊ��һ���ַ����ĳ���
    if(s1.empty() || s2.empty())
    {
        return s1.empty() ? s2.size() : s1.size();
    }
    
    //���һ���ֹԽ��
    vector<vector<int>> distance(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    
    //����߽�
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
            //��ǰ��̱༭��������Ǵ�s1�任Ҳ������s2�任һ��������ѡȡ��̵�
            distance[i][j] = 1 + min(distance[i - 1][j], distance[i][j - 1]);
            if(s1[i - 1] == s2[j - 1])
            {
                //�����ǰ�ַ���ȣ���˵��distance(i - 1, j - 1)���ñ任
                distance[i][j] = min(distance[i][j], distance[i - 1][j - 1]);
            }
            else
            {
                //�����ͬ������Ҫdistance(i - 1, j - 1)�任һ������
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
