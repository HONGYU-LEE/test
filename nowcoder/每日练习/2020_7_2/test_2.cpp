/*
�мٱ�
���ӣ�https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
��Դ��ţ����

��Ȼ�мٱң� �����������ˣ�����ũ��Ĺ���ȴ�����ǰ���ûǮ��ô�����Ⱑ��nowcoder���ȥ�����⣬�����������Ǯ���мٱң�������ϧnowcoder һ��С�İ��������һ���������ȥ�ˡ�ֻ֪���ٱҵ���������ҵ�����Ҫ�ᣬ����һ����ƽ����ƽ�������������޸�Ӳ�ң�����������ʱ����Ǹ��ɶ�ļٱ��ҳ�����

*/
// write your code here cpp
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int num;
    
    while(cin >> num)
    {
        if(num == 0)
            break;
        
        int count = 0, sum = 1;
        
        //ÿ����Ҫ��Ϊ3�飬����Աȣ�һ��۲죬��������г���һ���мٱң�������ж���һ�飬�����û�����ǹ۲�����顣
        while(num > 1)
        {
            //�ܸպ�������ֱ�ӳ�
            if(num % 3 == 0)
                num /= 3;
            //��������������ȡ��
            else
                num = num / 3 + 1;
            count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
