/*
https://www.nowcoder.com/questionTerminal/71d3849a19f04a1591c415964ac148f1
������
һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�
*/
//쳲���������
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<long long> res(91);
    res[0] = 1;
    res[1] = 1;
    
    for(size_t i = 2; i < 91; i++)
    {
        res[i] = res[i - 1] + res[i - 2];
    }
    
    int num;
    
    while(cin >> num)
    {
        cout << res[num] << endl;
    }
    return 0;
}

