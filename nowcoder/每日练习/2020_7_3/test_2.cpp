/*
���ӣ�https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
��Դ��ţ����

һ�����������Էֽ��һ����������Ļ�������36=2*2*3*3��������2��3�������ӡ�NowCoder������о����Ӹ����ķֲ����ɣ����ڸ���һϵ������������ϣ���㿪��һ���������ÿ�������������Ӹ�����
*/
// write your code here cpp
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//��Ŀû���������Ӧ������������


int main()
{
    int num;
    
    while(cin >> num)
    {
        int count = 0;
        for(size_t i = 2; i <= sqrt(num); i++)
        {
            if(num % i == 0)
            {
                count++;
                //�̳����ֽ�
                while(num % i == 0)
                {
                    num /= i;
                }
            }
        }
        
        //������л���һ��
        if(num != 1)
        {
            count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
