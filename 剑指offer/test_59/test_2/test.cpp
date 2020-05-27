class MaxQueue {
public:
    //�洢���ֵ�Ķ���
    deque<int> deq; 
    //�洢���ݵĶ���
    queue<int> data;

    MaxQueue() {
    }

    //�洢���ֵ
    int max_value() {
        if(deq.empty())
            return -1;

        return deq.front();
    }
    
    void push_back(int value) {
        //������б������С��ֵ
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

        //�����ǰ���ӵĶ��������ֵ����ͬʱ�������ֵ���еĶ��ף��������ֵΪ��һ��
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
