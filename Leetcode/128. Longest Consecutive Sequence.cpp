class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());
        
        int answer{};
        for(auto num : numbers) {
            if(numbers.find(num-1) != numbers.end()) {
                continue;
            }

            int count{};
            while(numbers.find(num++) != numbers.end()) {
                count++;
            }

            answer = max(answer, count);
        }

        return answer;
    }
};
