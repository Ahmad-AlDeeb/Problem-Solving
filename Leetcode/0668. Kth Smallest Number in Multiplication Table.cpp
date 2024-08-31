class Solution {
public:
    int countSmaller(int m, int n, int x) {
        int count{};
        for(int i{1}; i <= m; ++i) {
            count += min(x / i, n);
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int answer{3};
        int l{1}, r{m*n};
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int count = countSmaller(m, n, mid);
            
            if(count >= k) {
                r = mid - 1;
                answer = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return answer;
    }
};
