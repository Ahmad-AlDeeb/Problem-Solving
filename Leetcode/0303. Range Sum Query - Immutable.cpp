class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        prefix = nums;
        prefix.insert(prefix.begin(), 0); // insert dump val in the begining to handle left = 0

        for(int i{1}; i < prefix.size(); ++i) {
            prefix[i] += prefix[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        left++, right++;
        return prefix[right] - prefix[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
