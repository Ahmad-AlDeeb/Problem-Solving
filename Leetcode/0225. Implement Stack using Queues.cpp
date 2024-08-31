class MyStack {
    queue<int> queue;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        vector<int> temp;
        while(!queue.empty()) {
            temp.push_back(queue.front());
            queue.pop();
        }

        queue.push(x);
        for(auto element : temp)
            queue.push(element);
    }
    
    int pop() {
        int popped_element = queue.front();
        queue.pop();
        return popped_element;
    }
    
    int top() {
        return queue.front();
    }
    
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
