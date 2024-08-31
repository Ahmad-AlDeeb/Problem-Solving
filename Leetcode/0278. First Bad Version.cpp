// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left{1}, right{n}, ans{n};
        while(left <= right) {
            long long mid = (left+right)/2;
            if(isBadVersion(mid)) {
                right = mid - 1;
                ans = mid;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
