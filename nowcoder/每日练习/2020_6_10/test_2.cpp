/*
���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ����������������
*/

#include<iostream>
#include<vector>
/*
    �򵥵ĵݹ����⣬ûɶ��˵��
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
