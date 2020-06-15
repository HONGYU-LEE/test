/*
������
����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ-1�����ǶԷ���ҵ����ӡ�
*/


class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int row = board.size();
        int col = board[0].size();
        
        int i, j, count = 0;
        
        //�ж���
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
        
        //�ж���
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
        
        //�ж����Խ���
        count = 0;
        for(i = 0; i < row; i++)
        {
            count += board[i][i];
        }
        if(count == row)
            return true;
        
        //�жϸ��Խ���
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
