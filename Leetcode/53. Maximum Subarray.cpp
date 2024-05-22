class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx {INT_MIN};
        int sum {};

        for(auto num : nums) {
            sum += num;
            mx = max(mx, sum);
            if(sum < 0)
                sum = 0;
        }

        return mx;
    }
};
