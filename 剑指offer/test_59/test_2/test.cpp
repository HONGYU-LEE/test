class MaxQueue {
public:
    //存储最大值的队列
    deque<int> deq; 
    //存储数据的队列
    queue<int> data;

    MaxQueue() {
    }

    //存储最大值
    int max_value() {
        if(deq.empty())
            return -1;

        return deq.front();
    }
    
    void push_back(int value) {
        //清空所有比这个数小的值
        while(!deq.empty() && deq.back() <= value)
        {
            deq.pop_back();
        }

        deq.push_back(value);
        data.push(value);
    }
    
    int pop_front() {
        if(data.empty())
            return -1;

        int ret = data.front();

        //如果当前出队的队首是最大值，则同时出掉最大值队列的队首，更换最大值为下一个
        if(ret == deq.front())
        {
            deq.pop_front();
        }
        data.pop();
        
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
