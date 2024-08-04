class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> freq(31);
        int neg_count{};
        for(auto num : nums) {
            freq[abs(num)]++;
            
            if(num < 0) {
                neg_count++;
            }
        }

        vector<int> answer;
        for(auto num : nums) {
            bool is_neg = (neg_count%2) ? true : false;
            if(num < 0) {
                is_neg = !is_neg;
            }
            num = abs(num);
            
            
            int product{1};
            for(int j{}; j<=30; j++) {
                int exp = (num == j) ? freq[j] - 1 : freq[j];
                product *= pow(j,exp);
            }

            product *= (is_neg)? -1 : 1;
            answer.push_back(product);
        }
        return answer;
    }
};
