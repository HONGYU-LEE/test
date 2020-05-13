class Solution {
public:

    bool scanDigit(string s, int& i)
    {
        int count = i;

        while(i != s.size())
        {
            if(isdigit(s[i]))
                ++i;
            else
                break;
        }

        return i > count;
        //���������û��һ�����֣���ֱ�ӷ���false�����򷵻�true
    }

    bool scanSign(string s, int& i)
    {
        if(i < s.size() && s[i] == '+' || s[i] == '-')
        {
            ++i;
        }
        //����������

        return scanDigit(s, i);
    }

    bool isNumber(string s) {
        if(s.empty())
            return false;

        int i = 0;

        while(s[i] == ' ')
            ++i;
        //�����ײ��ո�

        bool ret = scanSign(s, i);
        //��һ��������������.��eǰ����������

        if(i < s.size() && s[i] == '.')
        {
            ret = scanDigit(s, ++i) || ret;
            //.ǰ�����ʲô��û�У�����Ҳ����ʲô��û�У�ֻҪ��һ�������ݾ���
        }

        //.�ĺ��������e����e�ĺ��治����.,�����ȴ���.�ٴ���e
        if(i < s.size() && (s[i] == 'e' || s[i] == 'E'))
        {
            ret = scanSign(s, ++i) && ret;
            //e��ǰ����붼Ҫ������,����e������Դ��������ţ�������Ҫ����������
        }

        while(s[i] == ' ')
            ++i;
        //��Ϊ�ո�ֻ�ܳ�����ĩβ���ײ������˿ո�

        return ret && (i == s.size());
        //��e���������ݣ������ַ���ȫ�����꣬˵�����ݳ���
    }
};
