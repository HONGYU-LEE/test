/*
ϴ��
https://www.nowcoder.com/practice/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0?tpId=85&&tqId=29848&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
ϴ����������ʮ�ֳ�����������Ҫдһ������ģ��ϴ�ƵĹ��̡� ������Ҫϴ2n���ƣ����ϵ��������ǵ�1�ţ���2�ţ���3��һֱ����2n�š����ȣ����ǰ���2n���Ʒֳ����ѣ��������ŵ�1�ŵ���n�ţ��ϰ�ѣ����������ŵ�n+1�ŵ���2n�ţ��°�ѣ������žͿ�ʼϴ�ƵĹ��̣��ȷ������ֵ����һ���ƣ��ٷ������ֵ����һ���ƣ����ŷ������ֵĵ����ڶ����ƣ��ٷ������ֵĵ����ڶ����ƣ�ֱ�����������ֵĵ�һ���ơ����Ű��ƺϲ������Ϳ����ˡ� ������6���ƣ��ʼ�Ƶ�������1,2,3,4,5,6�����ȷֳ����飬��������1,2,3����������4,5,6����ϴ�ƹ����а�˳�������6,3,5,2,4,1�������������ٴκϳ�һ����֮�����ǰ��մ������µ�˳�������ƣ��ͱ��������1,4,2,5,3,6�� ���ڸ���һ��ԭʼ���飬������⸱��ϴ��k��֮��������µ����С�
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int team;
    cin >> team;
    
    while(team--)
    {
        int num, k;
        cin >> num >> k;
        //????
        vector<int> cards(num * 2);
        
        for(size_t i = 0; i < num * 2; i++)
        {
            cin >> cards[i];
        }
        
        while(k--)
        {
            vector<int> temp(cards);
            //??
            for(size_t i = 0; i < num; i++)
            {
                cards[2 * i] = temp[i];
                cards[2 * i + 1] = temp[i + num];
            }
        }
        
        //??
        for(size_t i = 0; i < num * 2; i++)
        {
            cout << cards[i] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}

