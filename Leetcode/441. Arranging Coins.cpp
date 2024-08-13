class Solution {
public:
    long long getCoins(long long stairs) {
        return (1+stairs) * stairs / 2;
    }
    int arrangeCoins(int n) {
        long long ans{1}, l{1}, r{100000};
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            if(getCoins(mid) <= n) {
                l = mid + 1;
                ans = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }  
};
