/*
�Ϸ����������ж�
https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���

����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���

����������
"(()())",6
���أ�true
����������
"()a()()",7
���أ�false
����������
"()(()()",7
���أ�false
*/

/*
˼·����һ��ջ�����������ַ��������ǰΪ)��ƥ��ջ�����ݣ����ջ����Ϊ(����Ϊ�գ���˵����ƥ�䡣
�������ʱջΪ�գ����������(�õ�ƥ�䣬����true 
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
