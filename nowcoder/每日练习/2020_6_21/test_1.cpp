/*
��ˮƿ 
https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ�������5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�
*/

#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int num;
    
    while(cin >> num)
    {
        int count = 0;
        int empty = num;
        int lost = num;
        
        while(empty > 2)
        {
            lost = empty % 3;
            empty /= 3;
            count += empty;
            
            empty += lost;
            
            if(empty == 2)
            {
                count++;
                break;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
