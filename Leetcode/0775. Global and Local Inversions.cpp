class Solution {

    bool swapAdjacentAndCheckIfSorted(int startIndex, vector<int> nums) {
        for(int i{startIndex}; i < nums.size() - 1;) {
            if(nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
                i += 2;
            }
            else i++;
                
        }
        return is_sorted(nums.begin(), nums.end());
    }

public:
    bool isIdealPermutation(vector<int>& nums) {
        return swapAdjacentAndCheckIfSorted(0, nums);           
    }
};
