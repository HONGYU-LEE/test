/*
合法括号序列判断
https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。

给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

测试样例：
"(()())",6
返回：true
测试样例：
"()a()()",7
返回：false
测试样例：
"()(()()",7
返回：false
*/

/*
思路：用一个栈来保存所有字符，如果当前为)则匹配栈中数据，如果栈顶不为(或者为空，则说明不匹配。
如果结束时栈为空，则代表所有(得到匹配，返回true 
*/
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> s1;
        s1.push(A[0]);
        
        for(size_t i = 1; i < A.size(); i++)
        {
            if(A[i] == ')')
            {
                if(s1.empty() || s1.top() != '(')
                    return false;
                else
                    s1.pop();
            }
            else
            {
                s1.push(A[i]);
            }
        }
        
        
        if(s1.empty())
        {
            return true;
        }
        
        return false;
    }
};
