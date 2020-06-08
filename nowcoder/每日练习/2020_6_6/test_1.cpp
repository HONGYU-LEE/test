/*
不要二
https://www.nowcoder.com/practice/1183548cd48446b38da501e58d5944eb?tpId=85&&tqId=29840&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。
*/ 
/*
	首先初始化标志矩阵，如果位置为1则说明可以放蛋糕，为0则不能
	接着观察公式，发现欧几里得距离其实就是横坐标之差的平方加上纵坐标之和的平方再开方。
	所以继续推导，当欧几里得距离为2时，说明横纵坐标只能有一方有差值，另一方相同，并且差值只能为2
	比如：(0, 0) 和 (2, 0) (0, 2) 
*/
 


#include<iostream>
#include<vector>

using namespace std;
int main()
{
	size_t row, col;

	while (cin >> row >> col)
	{
		size_t res = 0;
        //首先初始化标志矩阵，如果位置为1则说明可以放蛋糕，为0则不能
		vector<vector<int>> flag(row, vector<int>(col, 1));

		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				//如果为1则说明可以存放 
				if (flag[i][j] == 1)
				{
					res++;
					//判断对应位置 
					if (i + 2 < row)
					{
						flag[i + 2][j] = 0;
					}

					if(j + 2 < col)
					{
						flag[i][j + 2] = 0;
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
