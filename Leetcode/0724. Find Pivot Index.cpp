class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(nums);
        
        for(int i{1}; i < size; ++i) {
            prefix[i] += prefix[i - 1];
        }

        if(prefix[size - 1] - nums[0] == 0) {
            return 0;
        }
        
        for(int i{1}; i < size; ++i) {
            int leftSum = prefix[i - 1];
            int rightSum = prefix[size - 1] - prefix[i];
            
            if(leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};
