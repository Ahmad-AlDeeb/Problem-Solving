class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        auto it = s.end();
        it--;
        
        if(s.size() < 3) {
            return *it;
        }

        it--; it--;
        return *it;
    }
};
