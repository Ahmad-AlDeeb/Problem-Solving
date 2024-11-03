class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto num : nums) {
            freq[num]++;
        }

        int operations{};

        for(auto num : nums) {
            int target = k  - num;
            if(target == num) {
                int count = freq[num] / 2;
                freq[num] -= count * 2;

                operations += count;
            }
            else if(freq[num] && freq[target]) {
                int count = min(freq[num], freq[target]);
                freq[num] -= count;
                freq[target] -= count;

                operations += count;
            }
        }
        return operations;
    }
};
