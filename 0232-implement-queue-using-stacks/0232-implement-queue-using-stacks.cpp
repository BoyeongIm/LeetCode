class MyQueue {
public:
    MyQueue() {    }
    stack<int> instack;
    stack<int> outstack;
    
    void push(int x) {
        instack.push(x);
    }
    
    int pop() {
        this->peek();
        int x = outstack.top();
        outstack.pop();
        return x;
    }
    
    int peek() {
        if (outstack.empty()) {
            while (!instack.empty()) {
                int x = instack.top();
                instack.pop();
                outstack.push(x);
            }
        }

        return outstack.top();
    }
    
    bool empty() {
        if (instack.empty() && outstack.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */