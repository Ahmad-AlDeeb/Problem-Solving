class Solution {
    int maxValue{};
    
    void calcMaxValue(vector<int>& nums) {
        for(auto num : nums) {
            maxValue |= num;
        }
    }

    int countSets(vector<int>& nums, int index, int curValue) {
        if(index >= nums.size()) {
            return (curValue == maxValue)? 1 : 0;
        }

        int withoutPath = countSets(nums, index + 1, curValue);
        int withPath    = countSets(nums, index + 1, curValue | nums[index]);
        return withoutPath + withPath;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        calcMaxValue(nums);
        return countSets(nums, 0, 0);
    }
};
