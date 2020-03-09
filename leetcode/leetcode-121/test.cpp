class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;

        int buy = -prices[0], sell = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            buy = max(buy, -prices[i]);
            sell = max(sell, prices[i] + buy);
        }
		//��̬�滮�� �����ǰ�۸��ǰһ��;͹��룬����ۼ۸��ڳɱ����۳� 
        return sell;
    }
};
