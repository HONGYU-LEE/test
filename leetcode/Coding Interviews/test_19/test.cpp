//����һ����ָoffer�ķ��������������Ȼ˼·���������ǵݹ��ظ�����ͬ��������ݣ�Ч�ʹ��ͣ�ͬʱ���ظ��ıȽϡ�
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str == nullptr || pattern == nullptr)
            return false;
        
        return coreMatch(str, pattern);
    }
    
    bool coreMatch(char* str, char* pattern)
    {
        if(!*str && !*pattern)
            return true;
        //������ȫ�������ʱ��˵��ƥ��ɹ�
        
        if(*str && !*pattern)
        //����ַ���ûƥ��������ʽ�Ѿ����꣬˵����ƥ�䡣
            return false;
        
        if(*(pattern + 1) == '*')
        {
            //�����һλ��*,����ʱ�м������
            if(*str == *pattern || (*pattern == '.' && *str != '\0'))
            {
                /*1.��Ϊ*����ǰ����ַ�����ƥ��N�Σ��������ƥ��N��Σ�str��һֱǰ��ֱ��
                  ����һλ��ƥ�䣬
                  2.���ֻƥ��һ�Σ��ַ���ǰ�������ʽԽ��*
                  3.���һ�ζ���ƥ�䣬��ֱ֮�ӿ�Խ��*����
                */
                return coreMatch(str + 1, pattern)
                    || coreMatch(str + 1, pattern + 2)
                    || coreMatch(str, pattern + 2);
            }
            else
            {
                //��ǰλ�ò�ƥ�䣬���ԣ�ֱ��Խ��*����
                return coreMatch(str, pattern + 2);
            }
        }
        else
        {
            if(*str == *pattern || (*pattern == '.' && *str != '\0'))
            {
                return coreMatch(str + 1, pattern + 1);
            }
        }
        
        //�������ȫ�����꣬˵����λ�ü�û��*��.��Ҳ��ƥ�䣬˵��ƥ��ʧ�ܡ�
        return false;
    }
};
//��������ͨ��substrÿ�δ����ִ����������������ݾ�Խ��ԽС 
class Solution {
public:
    bool isMatch(string s, string p)
    {
        if(p.empty() && s.empty())
            return true;
        
        if(p.empty() && !s.empty())
        {
            return false;
        }

		//�жϵڶ���λ���Ƿ���*����Ϊÿ�ζ������Ӵ�������ֻ��Ҫ�жϵڶ���λ�� 
        if(p[1] == '*')
        {
            if(s[0] == p[0] || (p[0] == '.' && !s.empty()))
            {
                //���������Ĳ�ͬ��ʡȥ��s + 1, p + 2.��Ϊ�Ѿ���������s,p + 1��
                return isMatch(s, p.substr(2))
                    || isMatch(s.substr(1), p);
            }
            else
            {
                return isMatch(s, p.substr(2));
            }
        }
        else
        {
            if(s[0] == p[0] || (p[0] == '.' && !s.empty()))
            {
                return isMatch(s.substr(1), p.substr(1));
            }
            else
            {
                return false;
            }
        }

    }
};
