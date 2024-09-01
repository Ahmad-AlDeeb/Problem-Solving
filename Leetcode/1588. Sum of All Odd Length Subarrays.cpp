class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum{};

        for(int i{}; i < n; ++i) {
            int count = ceil((i + 1) * (n - i) / 2.0);
            sum += arr[i] * count;
        }

        return sum;
    }
};
