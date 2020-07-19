/*
���ӣ�https://www.nowcoder.com/questionTerminal/ed9bc679ea1248f9a3d86d0a55c0be10
��Դ��ţ����
Ģ����
��������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�A��(1,1),B��(n,m)������A��Ҫ�ݷ�B��������ֻ��ȥB�ļң�����ÿ����ֻ����(i,j+1)��(i+1,j)������·�ߣ��ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����),�ʣ�A���ÿһ�����ѡ��Ļ�(�����ڱ߽��ϣ���ֻ��һ��ѡ��)����ô��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�
*/ 
#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;

int main()
{
    int n, m, k;
    while(cin >> n >> m >> k)
    {
        vector<vector<int>> vec((n + 1), vector<int>(m + 1));
        
        for(size_t i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            vec[x][y] = 1;
        }
        //���ʾ���
        vector<vector<double>> p((n + 1), vector<double>(m + 1));
        
        p[1][1] = 1.0;
        int i, j;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                //�������
                if(!(i == 1 && j == 1))
                {
                    //�ߵ���ǰλ�õĸ���Ϊ�ֱ�������λ�õĸ��ʵĺ͵�һ�롣
                     p[i][j] = p[i - 1][j] * (j == m ? 1 : 0.5) + p[i][j - 1] * (i == n ? 1 : 0.5);
                }
                
                //�����λ����Ģ��������ǰ��
                if(vec[i][j] == 1)
                {
                    p[i][j] = 0;
                }
            }
        }
        
        cout << fixed << setprecision(2) << p[n][m] << endl;
    }
    return 0;
}
