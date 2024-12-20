class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> unique;
        
        int first{};
        for(int second{}; second < nums.size(); ++second) {
            int currentNumber = nums[second];
            
            if(unique.count(currentNumber) == 0) {
                unique.insert(currentNumber);
                nums[first++] = currentNumber;
            }
        }
        return first;
    }
};
