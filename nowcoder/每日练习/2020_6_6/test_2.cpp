/*
���ַ���ת��������
https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0

ÿ�ν���һ�κͽ�λ*10�����ϵ�ǰλ���� 
*/

class Solution {
public:
    int StrToInt(string str) {
        int res = 0;
        size_t i = 0;
        int flag = 1;
        
        if(str[i] == '-')
        {
            flag = -1;
            i++;
        }
        else if(str[i] == '+')
        {
            flag = 1;
            i++;
        }
        
        for(; i < str.size(); i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                res = res * 10 + (str[i] - '0');
            }
            else
            {
                return 0;
            }
        }

        return res * flag;
    }
};
