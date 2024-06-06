class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum{};
        for(auto num : nums)
            sum += num;
        
        int size = nums.size();
        return (1+size) * size/2 - sum;
    }
};
