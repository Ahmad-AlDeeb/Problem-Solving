class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int MAX_SIZE = 50000;
        vector<int> positive(MAX_SIZE+1), negative(MAX_SIZE+1);

        for(auto num : nums) {
            if(num >= 0) {
                positive[num]++;
            }
            else {
                negative[abs(num)]++;
            }
        }

        int n = nums.size();
        vector<int> answer(n);
        int answer_i{};
        for(int i{MAX_SIZE}; i>0; i--) {
            while(negative[i]--) {
                answer[answer_i++] = -i;
            }
        }

        for(int i{}; i<=MAX_SIZE; i++) {
            while(positive[i]--) {
                answer[answer_i++] = i;
            }
        }

        return answer;
    }
};
