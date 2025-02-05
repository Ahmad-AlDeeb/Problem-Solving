class Solution {
    stack<string> s;

    pair<int, int> getNums() {
        int dig2 = stoi(s.top());
        s.pop();
        int dig1 = stoi(s.top());
        s.pop();

        return make_pair(dig1, dig2);
    }

    void makeOperation(pair<int,int> nums, string op) {
        int newNum;

        switch(op[0]) {
            case '+':
                newNum = nums.first + nums.second;
                break;
            case '-':
                newNum = nums.first - nums.second;
                break;
            case '*':
                newNum = nums.first * nums.second;
                break;
            case '/':
                newNum = nums.first / nums.second;
                break;
        }

        s.push(to_string(newNum));
    }

public:
    int evalRPN(vector<string>& tokens) {
        for(auto token : tokens) {
            if(s.empty()) {
                s.push(token);
                continue;
            }

            if(isdigit(token.back())) {
                s.push(token);
            }
            else {
                auto nums = getNums();
                makeOperation(nums, token);
            }
        }
        return stoi(s.top());
    }
};
