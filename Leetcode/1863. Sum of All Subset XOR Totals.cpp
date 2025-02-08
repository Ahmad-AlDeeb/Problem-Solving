class Solution {
    int sum{};

    void calcXOR(vector<int>& nums, int index, int sumXOR) {
        if(index >= nums.size()) {
            sum += sumXOR;
            return;
        }

        calcXOR(nums, index + 1, sumXOR);
        calcXOR(nums, index + 1, sumXOR ^ nums[index]);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        calcXOR(nums, 0, 0);
        return sum;
    }
};
