/*
iNOC产品部-杨辉三角的变形
https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43?tpId=37&&tqId=21276&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
			 1
         1  1  1
      1  2  3  2  1
   1  3  6  7  6  3  1
1  4  10 16 19  16 10  4  1
以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    size_t num;
    size_t i, j;
    while(cin >> num)
    {
        vector<vector<int>> res(num, vector<int>(2 * num - 1,0));
        int ret = -1;
        res[0][0] = 1;
        for(i = 1; i < num; i++)
        {
            res[i][0] = res[i][2 * i] = 1;
            
            for(j = 1; j < 2 * i; j++)
            {
                if(j == 1)
                    res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
                else
                    res[i][j] = res[i - 1][j - 2] + res[i - 1][j] + res[i - 1][j - 1];
            }
        }
        
        i--;
        for(j = 1; j < res[i].size() - 1; j++)
        {
            if(res[i][j] % 2 == 0)
            {
                ret = j + 1;
                break;
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}
