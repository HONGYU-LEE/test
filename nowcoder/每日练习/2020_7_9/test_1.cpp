/*
���ӣ�https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855
��Դ��ţ����
�ռ����б�
NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
���ڸ���һ���ռ����������������������Ӧ���ռ����б�
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int num;
    while(cin >> num)
    {
        string res;
        bool first = true;
        cin.get();
        for(size_t i = 0; i < num; i++)
        {
            string temp;
            getline(cin, temp);
           
            //û�пո�Ͷ���ʱ
            if(temp.find(' ') == string::npos && temp.find(',') == string::npos)
            {
                if(first == false)
                {
                    cout << ", ";
                }
                
                cout << temp;
            }
            else
            {
                if(first == false)
                {
                    cout << ", ";
                }
                
                cout << '"' << temp << '"';
            }
            first = false;
        }
        cout << endl;
    }
    return 0;
}
