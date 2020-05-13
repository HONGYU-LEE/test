class Solution {
public:
    void Print(vector<vector<int>>& matrix, vector<int>& ret, int row, int col, int rows, int cols)
    {
        //只剩最后一行时
        if(row == rows)
        {
            while(col <= cols)
            {
                ret.push_back(matrix[row][col]);
                ++col;
            }
            return;
        }

        //只剩一列时
        if(col == cols)
        {
            while(row <= rows)
            {
                ret.push_back(matrix[row][col]);
                ++row;               
            }
            return;
        }

        //从左往右
        int i = col;
        for(i = col; i < cols; i++)
        {
            ret.push_back(matrix[row][i]);   
        }

        //从上往下
        int j = row;
        for(j = row; j < rows; j++)
        {
            ret.push_back(matrix[j][i]);            
        }

        //从右往左
        for(; i > row; i--)
        {
            ret.push_back(matrix[j][i]);              
        }

        //从下往上
        for(; j > col; j--)
        {
            ret.push_back(matrix[j][i]);  
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
        {
            return {};
        }

        int row = 0, col = 0;
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;

        vector<int> ret;
        ret.reserve(rows * cols);
        //预分配capacity

        while(row <= rows && col <= cols)
        {
            Print(matrix, ret, row++, col++, rows--, cols--);
            //收缩边界
        }

        return ret;
    }
};
