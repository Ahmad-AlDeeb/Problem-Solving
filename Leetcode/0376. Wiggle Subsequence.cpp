////////////////////////////////////////////////////////////
///////////////////// Greedy Solution /////////////////////
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


////////////////////////////////////////////////////////////
/////////////////////// DP Solution ///////////////////////
class Solution {
    int cache[1000 + 5][2];
    vector<int> nums;
    enum CHOICE {UP = true, DOWN = false};
    int size;

    int getMaxLength(int index, bool choice) {
        if(index >= size) {
            return 0;
        }

        int &maxLength = cache[index][choice];
        if(maxLength != -1) {
            return maxLength;
        }

        int takeOption{};
        if(choice == UP && nums[index] > nums[index - 1] ||
           choice == DOWN && nums[index] < nums[index - 1]) {
                takeOption = 1 + getMaxLength(index + 1, !choice);
        }
        int skipOption = getMaxLength(index + 1, choice);

        return maxLength = max(takeOption, skipOption);
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        this->nums = nums;
        size = this->nums.size();
        memset(cache, -1, sizeof(cache));

        return 1 + max(getMaxLength(1, UP), getMaxLength(1, DOWN));
    }
};
