class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> Min;
    //一个保存数据的data栈和一个保存最小和次小的min栈
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
            如果最小栈为空或者x比最小值小，将其放入最小栈作为最小值，
            如果比最小值大，则再将最小值入栈，保证两个栈长度相同
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
