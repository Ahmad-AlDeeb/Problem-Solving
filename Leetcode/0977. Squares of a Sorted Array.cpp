class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int zeros{};
        int pos_i{}, neg_i{-1};
        // Detect last index of neg values & number of zeros & first index of pos values
        for(; pos_i<nums.size(); pos_i++) {
            if(nums[pos_i] > 0)
                break;
            else if(nums[pos_i] < 0)
                neg_i = pos_i;
            else 
                zeros++;
        }

        // Prepare vector to be filled and retruned as the answer
        vector<int> ans (nums.size());
        int ans_i{zeros};

        // Two-pointer appraoch where the smaller of neg between pos values go first into ans
        while(neg_i > -1 && pos_i < nums.size()) {
            int pos = nums[pos_i] * nums[pos_i];
            int neg = nums[neg_i] * nums[neg_i];
            
            
            if(pos < neg) {
                ans[ans_i++] = pos;
                pos_i++;
            }
            else {
                ans[ans_i++] = neg;
                neg_i--;
            }
        }

        // If any remaining neg values
        while(neg_i > -1) {
            int neg = nums[neg_i] * nums[neg_i];
            ans[ans_i++] = neg;
            neg_i--;
        }

        // If any remaining pos values
        while(pos_i < nums.size()) {
            int pos = nums[pos_i] * nums[pos_i];
            ans[ans_i++] = pos;
            pos_i++;
        }

        return ans;
    }
};
