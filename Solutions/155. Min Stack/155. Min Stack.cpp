class MinStack {
public:
    MinStack() {
        
    }
    int mn=INT_MAX;
    stack<int> stk;
    void push(int val) {
        if(val<=mn){
            stk.push(mn);
            mn=val;
        }
        stk.push(val);
    }
    
    void pop() {
        if(stk.top()==mn){
            stk.pop();
            mn=stk.top();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mn;
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