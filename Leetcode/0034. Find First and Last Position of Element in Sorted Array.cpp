class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binary_search(nums.begin(), nums.end(), target)) {
            return vector<int>{-1,-1};
        }
        
        auto p = equal_range(nums.begin(), nums.end(), target);
        int first = p.first - nums.begin();
        int last = p.second- nums.begin();
        return vector<int>{first, last-1};
    }
};
