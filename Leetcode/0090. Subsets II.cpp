class Solution {
    set<multiset<int>> powerSet;

    void buildPowerSet(vector<int>& nums, multiset<int> curSet, int index) {
        powerSet.insert(curSet);
        
        if(index >= nums.size()) {
            return;
        }

        buildPowerSet(nums, curSet, index + 1);

        curSet.insert(nums[index]);
        buildPowerSet(nums, curSet, index + 1);
    }   
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        multiset<int> curSet;
        buildPowerSet(nums, curSet, 0);

        vector<vector<int>> answer;
        for(auto s : powerSet) {
            answer.push_back(vector<int>(s.begin(), s.end()));
        }
        return answer;
    }
};
