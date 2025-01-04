class Solution {

public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int curSum = nums[0];
        
        for(int i{1}; i < n; ++i) {
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(maxSum, curSum);        
        }
        return maxSum;
    }
};
