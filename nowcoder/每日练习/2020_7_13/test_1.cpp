/*
�����	
��һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש����վ������һ���ɫ�Ĵ�ש�ϣ�ֻ�������ڵģ����������ĸ����򣩺�ɫ��ש�ƶ�����дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��
https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
*/ 
#include<iostream>
#include<vector>
using namespace std;

void func(int x, int y,  int& count, vector<vector<char>>& vec)
{
    if(x < 0 || y < 0 || x >= vec.size() || y >= vec[0].size() || vec[x][y] == '#')
        return;
    
    count++;
    //�߹���λ�ñ�ǣ���ֹ�ظ�����
    vec[x][y] = '#';
    
    //�ֱ����ĸ�λ��
    func(x + 1, y, count, vec);
    func(x - 1, y, count, vec);
    func(x, y + 1, count, vec);
    func(x, y - 1, count, vec);
}

int main()
{
    int m , n;
    
    while(cin >> m >> n)
    {
        int x, y;

        vector<vector<char>> vec(m, vector<char>(n));
        
        for(size_t i = 0; i < m; i++)
        {
            for(size_t j = 0; j < n; j++)
            {
                cin >> vec[i][j];
                
                if(vec[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        
        int count = 0;
        func(x, y, count, vec);
        
        cout << count << endl;
    }
    return 0;
}
