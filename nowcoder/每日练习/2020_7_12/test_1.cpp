/*
���ݿ����ӳ�
���ӣ�https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e
��Դ��ţ����

Webϵͳͨ����Ƶ���ط������ݿ⣬���ÿ�η��ʶ����������ӣ����ܻ�ܲΪ��������ܣ��ܹ�ʦ���������Ѿ����������ӡ����յ����󣬲������ӳ���û��ʣ����õ�����ʱ��ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻᱻ�������ӳ��У�����������ʹ�á�

�����ṩ�㴦���������־���������һ�����ӳ������Ҫ�������ٸ����ӡ�

*/
#include<vector>
#include<string>
#include<iostream>
using namespace std;

/*
	ά��һ�����飬����ǰ�������������������ʱ����� 
*/
int main()
{
    size_t num;
    
    while(cin >> num)
    {
        vector<string> vec;
        size_t max = 0;
        for(size_t i = 0; i < num; i++)
        {
            string id, option;
            cin >> id >> option;
            
            if(option == "connect")
            {
                vec.push_back(id);
            }
            else
            {
                for(size_t i = 0; i < vec.size(); i++)
                {
                    if(vec[i] == id)
                    {
                        vec.erase(vec.begin() + i);
                        break;
                    }
                }
            }
            
            if(vec.size() > max)
            {
                max = vec.size();
            }
        }
        
        cout << max << endl;
    }
}
