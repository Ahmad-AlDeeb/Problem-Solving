class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        
        vector<int> ans(2);
        for(int i{}; i<nums.size(); i++) {
            int needed = target - nums[i];

            if(m.find(needed) != m.end()) {
                ans[0] = i;
                ans[1] = m[needed];
                break;
            }
            else  m[nums[i]] = i;
        }

        return ans;
    }
};

