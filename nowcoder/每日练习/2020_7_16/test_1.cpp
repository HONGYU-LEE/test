/*
Emacs计算器
https://www.nowcoder.com/questionTerminal/1a92fbc771a54feb9eb5bd9b3ff2d0a9
Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，即运算符在操作数的后面。例如“2 3 +”等价于中缀表达式的“2 + 3”。
请你实现一个后缀表达式的计算器。
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int num;
    
    while(cin >> num)
    {
        stack<int> st;
        for(size_t i = 0; i < num; i++)
        {
            string str;
            cin >> str;
            
            if(str[0] >= '0' && str[0] <= '9')
            {
                st.push(stoi(str));
            }
            else
            {
                //先出栈的是右操作数
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                
                switch(str[0])
                {
                    case '+' :
                        st.push(left + right);
                        break;
                    case '-' :
                        st.push(left - right);
                        break;
                    case '*' :
                        st.push(left * right);
                        break;
                    case '/' :
                        st.push(left / right);
                        break;
                }
            }

        }
        cout << st.top() << endl;
    }
    return 0;
}
