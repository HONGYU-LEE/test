/*
���ӣ�https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b
��Դ��ţ����

NowCoder�����ڳ���Σ�պ���ı�������Ϊ�����棬���״η��������룬���ھ��ӵ���Ϣ���ݡ��������Ǿ����е�һ�����٣���Ҫ�ѷ���������Ϣ�������������
������Ľ�����
��Ϣ���ܵİ취�ǣ�����Ϣԭ���е�ÿ����ĸ���ֱ��ø���ĸ֮��ĵ�5����ĸ�滻�����磺��Ϣԭ���е�ÿ����ĸA ���ֱ��滻����ĸF���������ַ��� �䣬������Ϣԭ�ĵ�������ĸ���Ǵ�д�ġ������е���ĸ��ԭ���е���ĸ��Ӧ��ϵ���¡�
������ĸ��A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
ԭ����ĸ��V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
*/


// write your code here cpp
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string str;
    
    //��ʼ����ĸ��
    string hash;
    for(size_t i = 0; i < 26; i++)
    {
        hash += ('A' + i);
    }
    
    while(getline(cin, str))
    {
        string ret;
        int pos;
        
        for(auto ch : str)
        {
            if(ch >= 'A' && ch <= 'Z')
            {
                pos = ch - 'A' - 5;
                if(pos < 0)
                {
                    pos = 26 + pos;
                }
                
                ret += hash[pos];
            }
            else
            {
                ret += ch;
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}
