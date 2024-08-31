class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_stack, t_stack;
        for(auto c : s) {
            if(c == '#') {
                if(!s_stack.empty())
                    s_stack.pop();
            }
            else s_stack.push(c);
        }

        for(auto c : t) {
            if(c == '#') {
                if(!t_stack.empty())
                    t_stack.pop();
            }
            else t_stack.push(c);
        }

        string s_ans, t_ans;
        while(!s_stack.empty()) {
            s_ans += s_stack.top();
            s_stack.pop();
        }
        while(!t_stack.empty()) {
            t_ans += t_stack.top();
            t_stack.pop();
        }
        
        return s_ans == t_ans;
    }
};
