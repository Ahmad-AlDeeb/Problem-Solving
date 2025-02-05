class Solution {
    set<vector<int>> powerSet;

    void buildPowerSet(vector<int>& nums, vector<int>& curSet, int index) {
        powerSet.insert(curSet);
        
        if(index >= nums.size()) {
            return;
        }

        buildPowerSet(nums, curSet, index + 1);

        curSet.push_back(nums[index]);
        buildPowerSet(nums, curSet, index + 1);
        curSet.pop_back();
    }   
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curSet;
        buildPowerSet(nums, curSet, 0);
        
        return vector<vector<int>>(powerSet.begin(), powerSet.end());
    }
};
