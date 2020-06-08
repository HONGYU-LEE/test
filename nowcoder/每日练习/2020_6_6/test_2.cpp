/*
把字符串转换成整数
https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0

每次将上一次和进位*10，加上当前位即可 
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
