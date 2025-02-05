class MinStack {
    stack<pair<int, int>> elements;

public:
    MinStack() {

    }
    
    void push(int val) {
        if(elements.empty()) {
            elements.emplace(val, val);
        }
        else {
            int mini = min(elements.top().second, val);
            elements.emplace(val, mini);
        }
    }
    
    void pop() {
        elements.pop();
    }
    
    int top() {
        return elements.top().first;
    }
    
    int getMin() {
        return elements.top().second;
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
