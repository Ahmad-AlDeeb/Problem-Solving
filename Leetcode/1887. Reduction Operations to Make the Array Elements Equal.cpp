class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int op{};
        for(int i{1}; i<nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                op += i;
            }
        }
        return op;
    }
};
