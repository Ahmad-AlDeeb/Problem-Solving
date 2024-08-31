class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marks(n);
        
        int mx{nums[0]};
        int mn{nums[n-1]};
        for(int i{1}, j{n-2}; i<n; i++, j--) {
            int left {nums[i]};
            int right {nums[j]};
            
            if(left < mx) {
                marks[i] = true;
            }
            if(right > mn) {
                marks[j] = true;
            }

            mx = max(mx, left);
            mn = min(mn, right);
        }

        int first;
        for(int i{}; i<n; i++) {
            if(marks[i]) {
                first = i;
                break;
            }
            if(i == n-1) {
                return 0;
            }
        }

        int second;
        for(int i{n-1}; i>=0; i--) {
            if(marks[i]) {
                second = i;
                break;
            }
        }

        return second - first + 1;
    }
};
