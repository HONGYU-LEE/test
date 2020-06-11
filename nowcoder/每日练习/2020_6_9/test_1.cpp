/*
	�������򷽷�
	https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
	������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
"car" < "carriage" < "cats" < "doggies < "koala"
2.�����ַ����ĳ����������磺
"car" < "cats" < "koala" < "doggies" < "carriage"
������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
*/
 
/*
	ֱ�ӱ�����ͨ���Ƚϴ�С���ֽ������жϼ��� 
*/ 

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    size_t size = 0;
    bool flag1 = true, flag2 = true;
    
    while(cin >> size)
    {
        vector<string> str(size);
        
        for(size_t i = 0; i < size; i++)
        {
            cin >> str[i];
        }
        
        for(size_t i = 1; i < size; i++)
        {
            if(str[i] <= str[i - 1])
            {
                flag1 = false;
                break;
            }
        }
        
        for(size_t i = 1; i < size; i++)
        {
            if(str[i].size() <= str[i - 1].size())
            {
                flag2 = false;
                break;
            }
        }
        
        if(flag1 && flag2)
        {
            cout << "both" << endl;
        }
        else if(flag1 && !flag2)
        {
            cout << "lexicographically" << endl;
        }
        else if(!flag1 && flag2)
        {
            cout << "lengths" << endl;
        }
        else
        {
            cout << "none" << endl;
        }
    }
    return 0;
}
