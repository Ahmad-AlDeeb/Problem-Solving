class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> oneSums;
        int oneCount{};
        int answer{};

        for(int i{}; i < nums.size(); ++i) {
            if(nums[i]) {
                oneCount++;
            }
            else {
                if(oneCount)
                    oneSums.push_back(oneCount);
                answer = max(answer, oneCount);
                oneCount = 0;
                oneSums.push_back(0);
            }

            if(i == nums.size() - 1 && oneCount) {
                oneSums.push_back(oneCount);
                answer = max(answer, oneCount);
            }
        }

        cout << oneSums.size();
        for(int i{}; i < (int) oneSums.size() - 2; ++i) {
            if(oneSums[i])
                answer = max(answer, oneSums[i] + oneSums[i + 1] + oneSums[i + 2]);
        }
        if(oneSums.size() == 1 && answer) {
            return answer - 1;
        }
        return answer;
    }
};
