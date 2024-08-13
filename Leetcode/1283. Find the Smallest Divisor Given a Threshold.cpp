class Solution {
public:
    long long getSum(vector<int>& nums, int divisor) {
        long long sum{};
        for(int i{}; i<nums.size(); i++) {
            sum += ceil(nums[i] / (double) divisor);
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int answer{1000000};
        int l{1}, r{answer};
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(getSum(nums, mid) <= threshold) {
                r = mid - 1;
                answer = mid;
            }
            else {
                l = mid +1;
            }
        }
        return answer;
    }
};
