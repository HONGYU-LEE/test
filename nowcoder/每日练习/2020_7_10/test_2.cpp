/*
���ӣ�https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800
��Դ��ţ����
�����б�
NowCoderÿ��Ҫ��������ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�����Ϊ��Щ���͵��ʼ���Ҫ�Ա��Լ����ռ����б�����ʼ��ͣ������Ҫ���˵���Щ��Ҫ���ʼ������ȴ�����Ҫ���ʼ���
���ڸ���һ�������б������ж�Ŀ���û��Ƿ��ڳ����б��С�
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str))
    {
        size_t pos = 0;
        vector<string> res;
        
        while(pos < str.size())
        {
            //�������"����ȥƥ����һ��"
            if(str[pos] == '\"')
            {
                size_t end = str.find('\"', pos + 1);
                
                //����Ϊ�˺��淽��Ƚϣ�������""
                res.push_back(str.substr(pos + 1, end - pos - 1));
                
                //����,��"
                pos = end + 2;
            }
            else
            {
                //���û�г��֣���ֱ��ƥ������    
                size_t end = str.find(',', pos + 1);
                if(end == string::npos)
                {
                    //��ʱ˵������û�У� �����һ��������ֱ�Ӽ���
                    
                    res.push_back(str.substr(pos, str.size() - pos));
                    break;
                }
                
                
                res.push_back(str.substr(pos, end - pos));
                
                //����,
                pos = end + 1;
            }
        }
        
        string name;
        getline(cin, name);
        
        if(find(res.begin(), res.end(), name) != res.end())
        {
            cout << "Ignore" << endl;
        }
        else
        {
            cout << "Important!" << endl;
        }
        
    }
    return 0;
}
