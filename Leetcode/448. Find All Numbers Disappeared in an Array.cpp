class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> exist;
        for(auto num : nums) {
            exist.insert(num);
        }
        
        vector<int> answer;
        for(int num{1}; num <= nums.size(); ++num) {
            if(!exist.count(num)) {
                answer.push_back(num);
            }
        }

        return answer;
    }
};
