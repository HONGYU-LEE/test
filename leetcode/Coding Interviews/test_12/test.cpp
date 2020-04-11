
class Solution {
public:
    int rows, cols;
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        if(word.empty() || board.empty() || board[0].empty())
        {
            return false;
        }
    
        int path = 0;
        rows = board.size();
        cols = board[0].size();

        vector<bool> visit(rows * cols, false);

        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(dfs(board, visit, word, row, col, path))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<bool>& visit, string& word, int row, int col, int& path)
    {
        bool flag = false;
        if(path == word.size())
            return true;

        //˵���Ѿ����� 

        if(row < 0 || row >= rows || col < 0 || col >= cols 
            || visit[row * cols + col] 
            || board[row][col] != word[path])
        {
            return false;
        }
		//�߽���ơ�����߹��ˡ���λ�ò���ȷ�򷵻� 
		
        visit[row * cols + col] = true;
        ++path;

        flag = dfs(board, visit, word, row - 1, col, path)
            || dfs(board, visit, word, row + 1, col, path)
            || dfs(board, visit, word, row, col - 1, path)
            || dfs(board, visit, word, row, col + 1, path);

        //ƥ�����������ĸ�������û����ȷ�ַ�

        if(!flag)
        {
            --path;
            visit[row * cols + col] = false;
        }
        //��������ڣ�����ݵ�ԭ����λ�á�

        return flag;
    }
};




