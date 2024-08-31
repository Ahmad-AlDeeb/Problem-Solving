class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum{};
        int n = nums.size();
        for(int i{n-1}; i>=0; i-=2) {
            sum += nums[i-1];
        }
        return sum;
    }
};
