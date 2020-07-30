class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        a_.push(value);
    }
    
    int deleteHead() {
        if(b_.empty() && a_.empty())
        {
            return -1;
        }
        else if (b_.empty() && !a_.empty())
        {
            while(!a_.empty())
            {
                int o = a_.top();
                b_.push(o);
                a_.pop();
            }
        }
        int o = b_.top();
        b_.pop();
        return o;
    }
private:
    stack<int> a_;
    stack<int> b_;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */