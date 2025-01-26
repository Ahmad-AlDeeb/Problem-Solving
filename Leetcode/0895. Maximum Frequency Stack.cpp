class FreqStack {
	unordered_map<int, int> frequency;
    stack<int> elements;

    int findMostFrequent() {
        int mostFreq{};
        
        for(auto p : frequency) {
        	if(p.second > mostFreq) {
            	mostFreq = p.second;
            }
        }

        return mostFreq;
    }
  
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        frequency[val]++;
        elements.push(val);
    }
    
    int pop() {
        // Determine most frequent value
        int mostFreq = findMostFrequent();
        
        // Determine the target
        stack<int> tempStack;
        int target;
        while(true) {
        	int top = elements.top();
            elements.pop();
            
            if(frequency[top] == mostFreq) {
            	target = top;
                break;
            }
            tempStack.push(top);
        }
        
        // Restore popped elements back to stack from temp queue
        while(!tempStack.empty()) {
        	elements.push(tempStack.top());
            tempStack.pop();
        }
        
        frequency[target]--;
        return target;
    }
};
