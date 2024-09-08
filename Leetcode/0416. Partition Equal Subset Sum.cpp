class Solution {
    vector<vector<int>> memory;
    vector<int> v;
    bool checkSums(int i, int target) {
        if(target < 0) {
            return false;
        }

        if(i == v.size()) {
            if(!target) {
                return true;
            }
            return false;
        }

        int &answer = memory[i][target];
        if(answer != -1) {
            return answer;
        }

        int takeChoice = checkSums(i + 1, target - v[i]);
        int leaveChoice = checkSums(i + 1, target);
        return answer = takeChoice || leaveChoice;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum{};
        for(auto num : nums) {
            sum += num;
        }
        if(sum % 2) {
            return false;
        }
        
        const int N = 200;
        const int MAX = 20000 / 2;
        memory.resize(N, vector<int>(MAX, -1));
        v = nums;
        return checkSums(0, sum / 2);
    }
};
