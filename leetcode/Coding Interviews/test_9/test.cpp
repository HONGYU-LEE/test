class CQueue {
public:
    stack<int> pushS;
    stack<int> popS;

    CQueue() {

    }
    
    void appendTail(int value) {
        pushS.push(value);
    }
    
    int deleteHead() {
        if(popS.empty())
        {
            if(pushS.empty())
                return -1;

            while(!pushS.empty())
            {
                popS.push(pushS.top());
                pushS.pop();
            }
        }

        int ret = popS.top();
        popS.pop();

        return ret;
    }
};
