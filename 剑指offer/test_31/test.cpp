class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty() && popped.empty())
            return true;
        else if(pushed.empty() || popped.empty())
            return false;

        stack<int> data;
        //���ø���ջ
        int i = 0, j = 0;

        while(j < popped.size())
        {
            while(data.empty() || data.top() != popped[j])
            {
                if(i == pushed.size())
                    break;

                data.push(pushed[i++]);
            }
            //���ջ���ͳ�ջ˳��ͬ����һֱ��ջֱ����ͬ��ջ��ʱ����

            if(data.top() != popped[j])
                return false;
            //���ȫ����ջ���ǲ�һ����˵�����ջ˳��ƥ�䣬���ش���


            data.pop();
            ++j;     
            //��ͬ���ջ���Ա���һ��      
        }

        if(data.empty() && j == popped.size())
            return true;
        //�����ջ˳���������,����ջΪ�ղ��ҳ�ջ���б����꣬��˵����ȷ

        return false;
    }
};
