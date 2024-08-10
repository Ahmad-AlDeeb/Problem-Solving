class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // Start with biggest negative
        // finished all of them? if 0 exist it's abs sum of nums and if not we check remaining k if odd 
        
        sort(nums.begin(), nums.end());
        for(int i{}; i<nums.size() && k && nums[i]<0; i++,k--) {
            nums[i] = -nums[i];
        }

        sort(nums.begin(), nums.end());
        int sum{};
        bool zero_exist{false};
        for(auto num : nums) {
            sum += num;
            if(!num) {
                zero_exist = true;
            }
        }

        if(k%2 && !zero_exist) {
            sum -= (2*nums.front());
        }
        return sum;        
    }
};
