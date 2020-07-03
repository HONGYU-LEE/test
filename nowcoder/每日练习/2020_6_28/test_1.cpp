/*
�Ǽ�����
���ӣ�https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
��Դ��ţ����
�Ǽ�ս����չ��100��֮��NowCoder���������������˵����룡���ǵ�������һ��������ͨ��һ�ű������Ϣӳ�������4λ���롣��Ĺ����ǣ�n��Ӧ��ֵ�Ǿ���X��n�η������Ͻǣ�������������4λ����0��䣬�������4λ����ֻ������4λ��
|1 1|^n => |Xn ..|
|1 0|      |.. ..|
����n=2ʱ��
|1 1|^2 => |1 1| * |1 1| => |2 1|
|1 0|      |1 0|   |1 0|    |1 1|
��2��Ӧ�����ǡ�0002����
https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062

��ʵ����쳲���������
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    //���������10000�����Խ���һ��1w��С��쳲��������б�
    //0��λ�ò�����
    int arr[10001] = {1, 1};
    for(int i = 2; i < 10001; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10000;
    }
    
    int size = 0;
    
    while(cin >> size)
    {
        int index;
        for(int i = 0; i < size; i++)
        {
            cin >> index;
        
            printf("%04d", arr[index]);
        }
        
        cout << endl;
    }
    return 0;
}
