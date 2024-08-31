class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nums2(nums.size());

        int j{};
        for(int i{}; i<nums.size(); i++) {
            if(nums[i]) 
                nums2[j++] = nums[i];
        }

        nums = nums2;
    }
};
