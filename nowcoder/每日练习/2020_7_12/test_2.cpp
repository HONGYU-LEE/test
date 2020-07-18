/*
mkdir 
���ӣ�https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a
��Դ��ţ����

�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼��/usr/local/bin��������Ҫ�˴δ�����/usr������/usr/local���Լ���/usr/local/bin�������ڣ�Linux��mkdir�ṩ��ǿ��ġ�-p��ѡ�ֻҪһ�����mkdir -p /usr/local/bin�������Զ�������Ҫ���ϼ�Ŀ¼��
���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir -p�����
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    size_t num;
    
    while(cin >> num)
    {
        vector<string> res(num);
        vector<bool> flag(num, true);
        for(size_t i = 0; i < num; i++)
        {
            cin >> res[i];
        }
        //���������ݸ������ж�
        sort(res.begin(), res.end());
         
        for(size_t i = 1; i < num; i++)
        {
            //��ͬʱɾ������һ��
            if(res[i - 1] == res[i])
            {
                res[i - 1] = false;
            }
            //���ǰһ��Ϊ��һ���Ӵ�����ɾ���Ӵ�
            else if( res[i - 1].size() < res[i].size()
                     && res[i - 1] == res[i].substr(0, res[i - 1].size())
                     && res[i][res[i - 1].size()] == '/'
                   )
            {
                flag[i - 1] = false;
            }
            
        }
            
        for(size_t i = 0; i < num; i++)
        {
            if(flag[i] == true)
            {
                cout << "mkdir -p " << res[i] << endl;
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
