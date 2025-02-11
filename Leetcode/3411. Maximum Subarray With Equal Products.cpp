class Solution {
    int gcd(int a, int b) {
        if(b != 0) return gcd(b, a%b);
        else return a;
    }
    int lcm(int a, int b) {
        return a / gcd(a,b) * b;
    }

public:
    int maxLength(vector<int>& nums) {
        int answer{1};
        for(int start{}; start < nums.size(); ++start) {
            int prod{nums[start]};
            int GCD{nums[start]};
            int LCM{nums[start]};
            int count{1};

            for(int i{start + 1}; i < nums.size(); ++i) {
                if(prod * nums[i] == gcd(GCD, nums[i]) * lcm(LCM, nums[i])) {
                    count++;
                    answer = max(answer, count);

                    prod *= nums[i];
                    GCD = gcd(GCD, nums[i]);
                    LCM = lcm(LCM, nums[i]);
                }
                else break;
            }
        }
        return answer;
    }
};
