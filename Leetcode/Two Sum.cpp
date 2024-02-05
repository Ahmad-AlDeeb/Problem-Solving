class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums_origin = nums;
        sort(nums.begin(), nums.end());

        vector<int> ans;
        for(int i{}, j=nums.size()-1; i<nums.size();) {
            if(nums[i] + nums[j] < target) i++;
            else if(nums[i] + nums[j] > target) j--;
            else {
                for(int k{}; k<nums.size(); k++)
                    if(nums_origin[k] == nums[i] || nums_origin[k] == nums[j])
                        ans.push_back(k);
                break;
            }
        }
        return ans;
    }
};
