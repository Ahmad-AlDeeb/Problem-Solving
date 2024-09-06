class Solution {
    vector<vector<int>> memory;
    int LIS(int i, int prev_i, vector<int>& nums) {
        if(i == nums.size()) {
            return 0;
        }

        int &state = memory[i][prev_i];
        if(state != -1) {
            return state;
        }
        
        int takeOption{};
        if(prev_i == 2500 || nums[prev_i] < nums[i]) {
            takeOption = 1 + LIS(i + 1, i, nums);
        }
        
        int leaveOption = LIS(i + 1, prev_i, nums);

        return state = max(takeOption, leaveOption);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memory.resize(2500, vector<int>(2500 + 1, -1));
        return LIS(0, 2500, nums);
    }
};
