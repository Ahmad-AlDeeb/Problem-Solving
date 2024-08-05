class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> answer;
        for(int i{}; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }

            int j {i+1};
            int k {n-1};
            while(j < k) {
                int sum = nums[i] + nums[k] + nums[j];
                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    answer.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++, k--;
                    
                    while(j<k && nums[j] == nums[j-1])  {
                        j++;
                    }
                    while(j<k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }
            }
        }

        return answer;
    }
};
