/*
���ӣ�https://www.nowcoder.com/questionTerminal/3549ff22ae2c4da4890e9ad0ccb6150d
��Դ��ţ����
��������
NowCoder����һ����͵꣬��ҵ�Ŀ��˶��и���ֵ��ã�����ֻҪ����ҵ�Թ�һ����ͣ��ͻ�ÿ�춼���������ң�����������ҵ����������ͺ󣬽�����ÿ�춼���һλ������һ����Ʒ����
���ǣ���ҵ�Ŀ��˴����һ���˷�չ�ɺƺƵ����ɰ���ǧ�ˣ�1��1��2��3��5����
���ڣ�NowCoder�������æͳ��һ�£�ĳһ��ʱ�䷶Χ�����ܹ��������ٷ���ͣ�����ÿλ����ֻ��һ����ͣ���
*/
//쳲���������� 
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int num1, num2;
    vector<long long> ret(81);
    ret[0] = 0;
    ret[1] = 1;

    for(size_t i = 2; i < 81; i++)
    {
        ret[i] = ret[i - 1] + ret[i - 2];
    }
    
    while(cin >> num1 >> num2)
    {
        long long sum = 0;
        
        for(size_t i = num1; i <= num2; i++)
        {
            sum += ret[i];
        }
        
        cout << sum << endl;
    }
}
