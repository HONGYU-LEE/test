/*
迷宫问题
https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc?tpId=37&&tqId=21266&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），如5 × 5数组下所示： 


int maze[5][5] = {


        0, 1, 0, 0, 0,


        0, 1, 0, 1, 0,


        0, 0, 0, 0, 0,


        0, 1, 1, 1, 0,


        0, 0, 0, 1, 0,


};


它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。入口点为[0,0],既第一空格是可以走的路。

Input

一个N × M的二维数组，表示一个迷宫。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

Output

左上角到右下角的最短路径，格式如样例所示。

Sample Input

0 1 0 0 0

0 1 0 1 0

0 0 0 0 0

0 1 1 1 0

0 0 0 1 0

Sample Output

(0, 0)

(1, 0)

(2, 0)

(2, 1)

(2, 2)

(2, 3)

(2, 4)

(3, 4)

(4, 4)
*/

#include<iostream>
#include<vector>
using namespace std;

int rows, cols;

vector<vector<int>> map;
vector<vector<int>> bestPath;
vector<vector<int>> path;

void getPath(int row, int col)
{
    //标记当前节点，代表已走
    map[row][col] = 1;
    //加入当前路径
    path.push_back({row, col});
    
    //判断是否到达终点
    if(row == rows - 1 && col == cols - 1)
    {
        //如果路径更优，则更新最优路径
        if(bestPath.empty() || path.size() < bestPath.size())
        {
            bestPath = path;
        }
    }
    
    //判断各种方向
    //判断能否走上面
    if(row - 1 >= 0 && map[row - 1][col] == 0)
    {
        getPath(row - 1, col);
    }
    
    //判断能否走下面
    if(row + 1 < rows && map[row + 1][col] == 0)
    {
        getPath(row + 1, col);
    }
    
    //判断是否能走左边
    if(col - 1 >= 0 && map[row][col - 1] == 0)
    {
        getPath(row, col - 1);
    }
    
    //判断能否走右边
    if(col + 1 < cols && map[row][col + 1] == 0)
    {
        getPath(row, col + 1);
    }
    
    //回溯到走之前的状态，判断其他路径
    map[row][col] = 0;
    path.pop_back();
}

int main()
{
    while(cin >> rows >> cols)
    {
        map= vector<vector<int>>(rows, vector<int>(cols, 0));
        bestPath.clear();
        path.clear();
       
        for(size_t i = 0; i < rows; i++)
        {
            for(size_t j = 0; j < cols; j++)
            {
                cin >> map[i][j];
            }
        }
        
        getPath(0, 0);
        for(auto way : bestPath)
        {
            cout << '(' << way[0] << ',' << way[1] << ')' << endl;
        }
    }
    
    return 0;
}
