/*
红与黑	
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
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
    //走过的位置标记，防止重复计数
    vec[x][y] = '#';
    
    //分别走四个位置
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
