//方法一，剑指offer的方法，这个方法虽然思路清晰，但是递归重复拷贝同样大的数据，效率过低，同时有重复的比较。
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
        //当两边全部走完的时候说明匹配成功
        
        if(*str && !*pattern)
        //如果字符串没匹配完而表达式已经走完，说明不匹配。
            return false;
        
        if(*(pattern + 1) == '*')
        {
            //如果下一位是*,则这时有几种情况
            if(*str == *pattern || (*pattern == '.' && *str != '\0'))
            {
                /*1.因为*代表前面的字符可以匹配N次，所以如果匹配N多次，str就一直前进直到
                  与那一位不匹配，
                  2.如果只匹配一次，字符串前进，表达式越过*
                  3.如果一次都不匹配，则之直接跨越到*后面
                */
                return coreMatch(str + 1, pattern)
                    || coreMatch(str + 1, pattern + 2)
                    || coreMatch(str, pattern + 2);
            }
            else
            {
                //当前位置不匹配，忽略，直接越过*后面
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
        
        //如果上面全部走完，说明该位置既没有*和.，也不匹配，说明匹配失败。
        return false;
    }
};
//方法二，通过substr每次传递字串，这样拷贝的数据就越来越小 
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

		//判断第二个位置是否是*，因为每次都会拆分子串，所以只需要判断第二个位置 
        if(p[1] == '*')
        {
            if(s[0] == p[0] || (p[0] == '.' && !s.empty()))
            {
                //这里和上面的不同，省去了s + 1, p + 2.因为已经包含在了s,p + 1中
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
