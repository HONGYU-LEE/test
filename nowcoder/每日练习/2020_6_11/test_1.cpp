/*
井字棋
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
*/


class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int row = board.size();
        int col = board[0].size();
        
        int i, j, count = 0;
        
        //判断行
        for(i = 0; i < row; i++)
        {
            count = 0;
            for(j = 0; j < col; j++)
            {
                count += board[i][j];
            }
            
            if(count == row)
                return true;
        }
        
        //判断列
        for(i = 0; i < row; i++)
        {
            count = 0;
            for(j = 0; j < col; j++)
            {
                count += board[j][i];
            }
            
            if(count == row)
                return true;
        }
        
        //判断主对角线
        count = 0;
        for(i = 0; i < row; i++)
        {
            count += board[i][i];
        }
        if(count == row)
            return true;
        
        //判断副对角线
        count = 0;
        for(i = 0; i < row; i++)
        {
            count += board[i][row - i + 1];
        }
        if(count == row)
            return true;
        
        return false;
    }
};
