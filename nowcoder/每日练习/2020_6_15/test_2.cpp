/*
���˵Ĵ���
https://www.nowcoder.com/practice/a5190a7c3ec045ce9273beebdfe029ee?tpId=85&&tqId=29839&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
���磺��������������ĺ�����{1, 1, 2, 3}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getLuckyPacket(vector<int>& balls, size_t pos, int sum, int multi)
{
    int count = 0;
    
    for(size_t i = pos; i < balls.size(); i++)
    {
        //����˻����ۼӺ�
        sum += balls[i];
        multi *= balls[i];
        
        //������������¼��ǰ��ϣ����Ҽ���������������Ƿ�����
        if(sum > multi)
        {
            count += (1 + getLuckyPacket(balls, i + 1, sum, multi));
        }
        //�˻������ȣ���˵�����п�����������������������������
        else if(sum == multi)
        {
            count += getLuckyPacket(balls, i + 1, sum, multi);
        }
        //������������sum < multi�����ҳ˻�ֻ��Խ��Խ�󣬲��������㣬�����ж�
        else
        {
            break;
        }
        
        //���ݵ�ԭ����״̬������������һ�����
        sum -= balls[i];
        multi /= balls[i];
        
        //ȥ�أ������ظ�Ԫ����ֱ������
        while(i < balls.size() - 1 && balls[i] == balls[i + 1])
        {
            i++;
        }
    }
    
    return count;
}

int main()
{
    int n; 
    
    while(cin >> n)
    {
        vector<int> balls(n);
        
        for(int i = 0; i < n; i++)
        {
            cin >> balls[i];
        }
        
        //���� 
        sort(balls.begin(), balls.end());
        
        cout << getLuckyPacket(balls, 0, 0, 1) << endl;
    }
    
    return 0;
}
