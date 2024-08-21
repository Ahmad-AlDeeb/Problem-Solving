class Solution {
    bool process(int num, int goal, int states, queue<int>& q, vector<bool>& visited) {
        if(num == goal) {
            return true;
        }

        if(num >= 0 && num < states && !visited[num]) {
            visited[num] = true;
            q.push(num);
        }

        return false;
    }

public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int states {1001};
        vector<bool> visited(states);
        queue<int> q;
        q.push(start);

        for(int level{}, size{1}; !q.empty(); ++level, size = q.size()) {
            while(size--) {
                int current = q.front();
                q.pop();

                for(auto &num : nums) {
                    int addition {current + num};
                    int subtraction {current - num};
                    int XOR {current ^ num};
                    vector<int> operations {addition, subtraction, XOR};

                    for(auto &operation : operations) {
                        if(process(operation, goal, states, q, visited)) {
                            return level + 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
