class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int maxLength{1};
        int isPeak {-1};
        
        for(int i{1}; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]) {
                continue;   
            }
            
            if(isPeak == -1) {
                isPeak = nums[i] > nums[i-1];
                maxLength++;
                continue;
            }

            if(isPeak != (nums[i] > nums[i - 1])) {
                isPeak = !isPeak;
                maxLength++;
            }
        }
        return maxLength;
    }
};
