/*
https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
ɾ�������ַ�
��Ŀ����
���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
��������:
ÿ�������������2���ַ���
�������:
���ɾ������ַ���
ʾ��1
����
����
They are students. 
aeiou
���
����
Thy r stdnts.
*/

/*
	������ϣ����¼����str2���ַ����ֹ��Ĵ�����Ȼ�����str1���������ַ���str2���ֹ�������� 
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1, str2;
    while(getline(cin, str1) && getline(cin, str2))
    {
        //������ϣ�� ��¼����str2�����ַ����ֵĴ���
        int hash[256] = {0};
        
        for(size_t i = 0; i < str2.size(); i++)
        {
            //ֱ���ڶ�Ӧasciiֵ��λ�ü���
            hash[str2[i]]++;
        }
        
        string res;
        for(size_t j = 0; j < str1.size(); j++)
        {
        	//���û���ֹ������ 
            if(!hash[str1[j]])
            {
                res += str1[j];
            }
        }
            
        cout << res << endl;
    }
    
    return 0;
}
