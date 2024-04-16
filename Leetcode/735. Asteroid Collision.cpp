class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> s;
        for(int i{}; i<ast.size(); i++) {
            int cur {ast[i]};

            if(cur < 0) {
                bool equal{false};
                while(!s.empty() and s.top()>=0 and abs(cur) >= s.top()) {
                    if(abs(cur) == s.top()) {
                        s.pop();
                        equal=true;
                        break;
                    }
                    s.pop();
                }

                if((s.empty() or s.top()<0) and !equal) s.push(cur);
            }
            else s.push(cur);
        }

        
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
