/*
���������bit��
https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
����: һ��byte�͵�����
���: ��
����: ��Ӧ�Ķ�����������1�����������
*/
/*
˼·������32λ��ÿ���жϵ�ǰλ�Ƿ�Ϊ1������������������������������¼���������������ֵ����� 
*/

#include<iostream>

using namespace std;

int main()
{
    int num;
    
    while(cin >> num)
    {
        int count = 0, max = 0;
        for(int i = 0; i < 32; i++)
        {
            if(num % 2 == 1)
                count++;
            else
                count = 0;
            
            num >>= 1;
            
            if(count > max)
                max = count;
        }
        
        cout << max << endl;
    }
    return 0;
}
