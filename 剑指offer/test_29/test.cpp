class Solution {
public:
    void Print(vector<vector<int>>& matrix, vector<int>& ret, int row, int col, int rows, int cols)
    {
        //ֻʣ���һ��ʱ
        if(row == rows)
        {
            while(col <= cols)
            {
                ret.push_back(matrix[row][col]);
                ++col;
            }
            return;
        }

        //ֻʣһ��ʱ
        if(col == cols)
        {
            while(row <= rows)
            {
                ret.push_back(matrix[row][col]);
                ++row;               
            }
            return;
        }

        //��������
        int i = col;
        for(i = col; i < cols; i++)
        {
            ret.push_back(matrix[row][i]);   
        }

        //��������
        int j = row;
        for(j = row; j < rows; j++)
        {
            ret.push_back(matrix[j][i]);            
        }

        //��������
        for(; i > row; i--)
        {
            ret.push_back(matrix[j][i]);              
        }

        //��������
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
        //Ԥ����capacity

        while(row <= rows && col <= cols)
        {
            Print(matrix, ret, row++, col++, rows--, cols--);
            //�����߽�
        }

        return ret;
    }
};
