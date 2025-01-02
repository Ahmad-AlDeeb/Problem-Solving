class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum{};
        int size = gas.size();
        for(int i{}; i < size; ++i) {
            sum += gas[i] - cost[i];
        }

        if(sum < 0) {
            return -1;
        }

        int start{};
        sum = 0;
        for(int i{}; i < size; ++i) {
            sum += gas[i] - cost[i];
            if(sum < 0) {
                sum = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
