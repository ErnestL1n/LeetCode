class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> val,mn;
    MinStack() {
        
    }
    
    void push(int x) {
        val.push(x);
        if(mn.empty() || x<=getMin())
            mn.push(x);
    }
    
    void pop() {
        if(val.top()==getMin())
            mn.pop();
        val.pop();
    }
    
    int top() {
        return val.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */