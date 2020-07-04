/*
年终奖
https://www.nowcoder.com/practice/72a99e28381a407991f2c96d8cb238ab?tpId=49&&tqId=29305&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。

给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证每个礼物价值大于100小于1000。
*/

class Bonus {
public:
    /*
    动态规划写法，因为每次只能走下或者右，所以每次只选取一个方向。
    记录下走到每个位置时能够获取的最大价值
    状态方程f(i, j) = max(f(i, j - 1), f(i - 1, j)) + board[i][j];
    */
    int getMost(vector<vector<int> > board) {
        // write code here
        size_t i, j;
        vector<vector<int>> res(board.size(), vector<int>(board[0].size(), 0));
        //先处理直线
        res[0][0] = board[0][0];
        for(i = 1; i < board.size(); i++)
        {
            res[i][0] = res[i - 1][0] + board[i][0];
            res[0][i] = res[0][i - 1] + board[0][i];
        }
                                
        //处理每一个位置
        for(i = 1; i < board.size(); i++)
        {
            for(j = 1; j < board[0].size(); j++)
            {
                //加上前或者左的最大值
                res[i][j] = max(res[i - 1][j], res[i][j - 1]) + board[i][j];
            }
        }
        
        return res[i - 1][j - 1];
    }
};
