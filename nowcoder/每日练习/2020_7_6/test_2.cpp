/*
���ӣ�https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb
��Դ��ţ����
쳲�������β
NowCoder�ų��Լ��Ѿ���ס��1-100000֮�����е�쳲���������
Ϊ�˿���������������һ����n������˵����n��쳲�����������Ȼ��쳲���������ܴ���ˣ������n��쳲�����������6λ����˵������������ֻ˵�����6λ��
*/

//����6λʱ��ֻ��������λ��ֵ���� 
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{
    //�ȼ������ٸ������������ҡ�
    vector<int> res(100001, 0);
    res[0] = 1;
    res[1] = 1;
    for(size_t i = 2; i < 100001; i++)
    {
        res[i] = res[i - 1] + res[i - 2];
            
        if(res[i] > 999999)
        {
            res[i] %= 1000000;
        }
    }
    
    int num;
    
    while(cin >> num)
    {
        //������λ���Ų�0
        if(num > 29)
            cout << setfill('0') << setw(6) << res[num] << endl;
        else
            cout << res[num] << endl;
    }
    
    return 0;
}
