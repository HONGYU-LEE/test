/*
请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走
*/

#include<iostream>
#include<vector>
/*
    简单的递归问题，没啥好说的
*/
using namespace std;

int count(int row, int col, int rows, int cols)
{
    if(row == rows && col == cols)
        return 1;
    else if(row > rows || col > cols)
    {
        return 0;
    }
    
    return count(row + 1, col, rows, cols) + count(row, col + 1, rows, cols);
}

int main()
{
    int rows, cols;
    
    while(cin >> rows >> cols)
    {
        int res = 0;
        
        res = count(0, 0, rows, cols);
        cout << res << endl; 
    }
    return 0;
}
