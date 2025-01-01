#include <stack>
class MinStack {
public:
    stack<int> st;
    stack<int> minv;
    MinStack() {    }
    
    void push(int val) {
        st.push(val);
        if (minv.empty()) minv.push(val);
        else if (minv.top() > val) minv.push(val);
        else minv.push(minv.top());
    }
    
    void pop() {
        st.pop();
        minv.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minv.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */