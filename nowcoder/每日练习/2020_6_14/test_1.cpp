/*
��������
https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677?tpId=37&&tqId=21297&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
�������������������
xcopy /s c:\ d:\��
�����������£� 
����1��������xcopy 
����2���ַ���/s
����3���ַ���c:\
����4: �ַ���d:\
���дһ��������������ʵ�ֽ������и�����������������
�������� 
1.�����ָ���Ϊ�ո� 
2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy /s ��C:\program files�� ��d:\��ʱ��������Ȼ��4������3������Ӧ�����ַ���C:\program files��������C:\program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
3.���������� 
4.������������֤��������ֲ�����Ҫ������� 
*/

/*
ÿ�ζ�ȡһ�����ʷŽ�vector��,�����ǰ����˫���ţ��������˫�����е�����
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string str;

    while(getline(cin, str))
    {
        int count = 0;
        vector<string> res;
        
        auto start = str.begin();
        
        string temp;
        while(start != str.end())
        {
            if(*start == '"')
            {
                do
                {
                    temp += *start;
                    start++;
                }while(*start != '"');
                    
                temp.push_back(*start);
            }
            else if(*start != ' ')
            {
                temp += *start;
            }
            else
            {
                count++;
                res.push_back(temp);
                temp.clear();
            }
            
            start++;
        }
        count++;
        res.push_back(temp);
        
        cout << count << endl;
        
        for(const auto& i : res)
        {
            cout << i << endl;
        }
    }
    
    return 0;
}
