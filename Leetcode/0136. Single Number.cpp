class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer{};
        for(auto num : nums)
            answer ^= num;
        return answer;
    }
};
