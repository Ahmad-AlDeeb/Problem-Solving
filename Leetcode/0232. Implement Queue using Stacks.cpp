class MyQueue {
stack<int> push_stack, pop_stack;
public:
    MyQueue() {}
    
    void fill_pop_stack() {
        while(!push_stack.empty()) {
            pop_stack.push(push_stack.top());
            push_stack.pop();
        }
    }

    void push(int x) {
        push_stack.push(x);
    }
    
    int pop() {
        if(pop_stack.empty()) {
            fill_pop_stack();
        }
        
        int top = this->peek();
        pop_stack.pop();
        return top;
    }
    
    int peek() {
        if(pop_stack.empty()) {
            fill_pop_stack();
        }
        return pop_stack.top();
    }
    
    bool empty() {
        return push_stack.empty() && pop_stack.empty();
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
