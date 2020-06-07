/*
��������
https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&&tqId=29858&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3 
*/

/*
˼·1.��̬�滮
״̬���� dp[i] = max(dp[i - 1], 0) + data[i];

˼·2
�Ͷ�̬�滮һ��������С��0ʱ˵��������Ϊ��������ϣ����бض�����������̣��������¼��㣬�����ǰΪ�ʹ���0����ֱ�Ӽ��ϵ�ǰ���ݡ�
�����ݵ�ֵ�������ֵʱ��˵����������µ�������������к� 
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int count = 0;
    int size = 0;
        
    while(cin >> size)
    {
        vector<int> data(size);
        for(int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
        
        int max = data[0];
        for(int i = 0; i < size; i++)
        {
            if(count < 0)
            {
                count = data[i];
            }
            else
            {
                count += data[i];
            }
            
            if(count > max)
            {
                max = count;
            }
        }
        cout << max << endl;
    }
    
    return 0;
}

/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int count = 0;
    int size = 0;
        
    while(cin >> size)
    {
        vector<int> data(size);
        for(int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
        
        vector<int> dp(size);
        int res = data[0];
        dp[0] = data[0];
        
        for(size_t i = 1; i < data.size(); i++)
        {
            dp[i] = max(dp[i - 1], 0) + data[i];
            
            if(dp[i] > res)
            {
                res = dp[i];
            }
        }
        
        cout << res << endl;
    }
    
    return 0;
}
*/
