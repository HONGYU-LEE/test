class Solution {
public:
    int count = 0;
    int movingCount(int m, int n, int k) {
        vector<bool> visit(m * n , false);

        return dfs(visit, 0, 0, m, n, k);
    }

    int getDigitSum(int num)
    {
        int sum = 0;

        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int dfs(vector<bool>& visit, int row, int col, int rows, int cols, int k)
    {
        if(row < 0 || row >= rows || col < 0 || col >= cols 
            || visit[row * cols + col] 
            || (getDigitSum(row) + getDigitSum(col) > k))
        {
            return 0;
        }

        visit[row * cols + col] = true;

        return 1 + dfs(visit, row + 1, col, rows, cols, k)
            + dfs(visit, row - 1, col, rows, cols, k)
            + dfs(visit, row, col + 1, rows, cols, k)
            + dfs(visit, row, col - 1, rows, cols, k);
    }
};
