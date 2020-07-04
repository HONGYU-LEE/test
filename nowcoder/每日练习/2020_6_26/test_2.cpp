/*
�Թ�����
https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc?tpId=37&&tqId=21266&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
����һ����ά����N*M������2<=N<=10;2<=M<=10������5 �� 5��������ʾ�� 


int maze[5][5] = {


        0, 1, 0, 0, 0,


        0, 1, 0, 1, 0,


        0, 0, 0, 0, 0,


        0, 1, 1, 1, 0,


        0, 0, 0, 1, 0,


};


����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ���ڵ�Ϊ[0,0],�ȵ�һ�ո��ǿ����ߵ�·��

Input

һ��N �� M�Ķ�ά���飬��ʾһ���Թ������ݱ�֤��Ψһ��,�������ж�����������Թ�ֻ��һ��ͨ����

Output

���Ͻǵ����½ǵ����·������ʽ��������ʾ��

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
    //��ǵ�ǰ�ڵ㣬��������
    map[row][col] = 1;
    //���뵱ǰ·��
    path.push_back({row, col});
    
    //�ж��Ƿ񵽴��յ�
    if(row == rows - 1 && col == cols - 1)
    {
        //���·�����ţ����������·��
        if(bestPath.empty() || path.size() < bestPath.size())
        {
            bestPath = path;
        }
    }
    
    //�жϸ��ַ���
    //�ж��ܷ�������
    if(row - 1 >= 0 && map[row - 1][col] == 0)
    {
        getPath(row - 1, col);
    }
    
    //�ж��ܷ�������
    if(row + 1 < rows && map[row + 1][col] == 0)
    {
        getPath(row + 1, col);
    }
    
    //�ж��Ƿ��������
    if(col - 1 >= 0 && map[row][col - 1] == 0)
    {
        getPath(row, col - 1);
    }
    
    //�ж��ܷ����ұ�
    if(col + 1 < cols && map[row][col + 1] == 0)
    {
        getPath(row, col + 1);
    }
    
    //���ݵ���֮ǰ��״̬���ж�����·��
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
