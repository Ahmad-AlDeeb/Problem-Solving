class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int answer{};
        for(int i{}; i<n; i++) {
            for(int j{i+1}; j<n-1; j++) {
                int bound {nums[i] + nums[j]};
                auto bound_it = lower_bound(nums.begin()+j+1, nums.end(), bound);
                
                if(bound_it == nums.end()) {
                    answer +=  n - j - 1;
                }
                else {
                    answer +=  (bound_it - nums.begin()) - j - 1;
                }
            }
        }
        return answer;
    }
};
