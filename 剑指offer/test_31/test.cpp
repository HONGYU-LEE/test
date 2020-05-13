class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty() && popped.empty())
            return true;
        else if(pushed.empty() || popped.empty())
            return false;

        stack<int> data;
        //借用辅助栈
        int i = 0, j = 0;

        while(j < popped.size())
        {
            while(data.empty() || data.top() != popped[j])
            {
                if(i == pushed.size())
                    break;

                data.push(pushed[i++]);
            }
            //如果栈顶和出栈顺序不同，则一直入栈直到相同，栈满时则不如

            if(data.top() != popped[j])
                return false;
            //如果全部入栈后还是不一样，说明与出栈顺序不匹配，返回错误


            data.pop();
            ++j;     
            //相同则出栈并对比下一个      
        }

        if(data.empty() && j == popped.size())
            return true;
        //如果出栈顺序遍历完了,辅助栈为空并且出栈序列遍历完，则说明正确

        return false;
    }
};
