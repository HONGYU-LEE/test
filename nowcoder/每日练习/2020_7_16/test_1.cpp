/*
Emacs������
https://www.nowcoder.com/questionTerminal/1a92fbc771a54feb9eb5bd9b3ff2d0a9
Emacs�ų���ı༭�������Դ���һ������������������������ͬ�����ǻ��ں�׺���ʽ�ģ���������ڲ������ĺ��档���硰2 3 +���ȼ�����׺���ʽ�ġ�2 + 3����
����ʵ��һ����׺���ʽ�ļ�������
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
                //�ȳ�ջ�����Ҳ�����
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
