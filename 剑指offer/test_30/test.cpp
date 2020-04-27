class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> Min;
    //һ���������ݵ�dataջ��һ��������С�ʹ�С��minջ
    MinStack() {
    }
    
    void push(int x) {
        data.push(x);

        if(!Min.size() || x < Min.top())
        {
            Min.push(x);
        }
        else
        {
            Min.push(Min.top());
        }
        /*
            �����СջΪ�ջ���x����СֵС�����������Сջ��Ϊ��Сֵ��
            �������Сֵ�����ٽ���Сֵ��ջ����֤����ջ������ͬ
        */
    }
    
    void pop() {
        data.pop();
        Min.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return Min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
