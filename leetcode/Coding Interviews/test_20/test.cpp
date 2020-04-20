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
        //如果数据中没有一个数字，则直接返回false，有则返回true
    }

    bool scanSign(string s, int& i)
    {
        if(i < s.size() && s[i] == '+' || s[i] == '-')
        {
            ++i;
        }
        //过滤正负号

        return scanDigit(s, i);
    }

    bool isNumber(string s) {
        if(s.empty())
            return false;

        int i = 0;

        while(s[i] == ' ')
            ++i;
        //过滤首部空格

        bool ret = scanSign(s, i);
        //第一遍搜索，先走完.和e前的所有数字

        if(i < s.size() && s[i] == '.')
        {
            ret = scanDigit(s, ++i) || ret;
            //.前面可以什么都没有，后面也可以什么都没有，只要有一边有数据就行
        }

        //.的后面可以有e，但e的后面不能有.,所以先处理.再处理e
        if(i < s.size() && (s[i] == 'e' || s[i] == 'E'))
        {
            ret = scanSign(s, ++i) && ret;
            //e的前后必须都要有数据,并且e后面可以存在正负号，所以需要过滤正负号
        }

        while(s[i] == ' ')
            ++i;
        //因为空格只能出现在末尾和首部，过滤空格

        return ret && (i == s.size());
        //当e后面有数据，并且字符串全部走完，说明数据成立
    }
};
