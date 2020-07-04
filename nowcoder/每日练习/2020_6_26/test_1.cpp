/*
���ս�
https://www.nowcoder.com/practice/72a99e28381a407991f2c96d8cb238ab?tpId=49&&tqId=29305&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6*6�������Ͻ��У��������36����ֵ���ȵ����ÿ��С���������������һ���������Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ�����������½�ֹͣ��һ·�ϵĸ����������С�������õ��������һ���㷨ʹС���õ���ֵ��ߵ����

����һ��6*6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ,���Ͻ�Ϊ[0,0],�뷵���ܻ�õ�����ֵ����֤ÿ�������ֵ����100С��1000��
*/

class Bonus {
public:
    /*
    ��̬�滮д������Ϊÿ��ֻ�����»����ң�����ÿ��ֻѡȡһ������
    ��¼���ߵ�ÿ��λ��ʱ�ܹ���ȡ������ֵ
    ״̬����f(i, j) = max(f(i, j - 1), f(i - 1, j)) + board[i][j];
    */
    int getMost(vector<vector<int> > board) {
        // write code here
        size_t i, j;
        vector<vector<int>> res(board.size(), vector<int>(board[0].size(), 0));
        //�ȴ���ֱ��
        res[0][0] = board[0][0];
        for(i = 1; i < board.size(); i++)
        {
            res[i][0] = res[i - 1][0] + board[i][0];
            res[0][i] = res[0][i - 1] + board[0][i];
        }
                                
        //����ÿһ��λ��
        for(i = 1; i < board.size(); i++)
        {
            for(j = 1; j < board[0].size(); j++)
            {
                //����ǰ����������ֵ
                res[i][j] = max(res[i - 1][j], res[i][j - 1]) + board[i][j];
            }
        }
        
        return res[i - 1][j - 1];
    }
};
