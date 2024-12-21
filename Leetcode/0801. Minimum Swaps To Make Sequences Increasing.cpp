class Solution {
    const int MAX_CHANGES = 1e5;
    int cache[100001][2];
    int size;
    vector<int> nums1, nums2;
    
    int getCount(int index, bool isSwapped) {
        if(index >= size) {
            return 0;
        }

        int &count = cache[index][isSwapped];
        if(count != -1) {
            return count;
        }
        count = MAX_CHANGES;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if(isSwapped) {
            swap(prev1, prev2);
        }
        
        if(nums1[index] > prev1 && nums2[index] > prev2) {
            count = min(count, getCount(index + 1, false));
        }
        if(nums1[index] > prev2 && nums2[index] > prev1) {
            count = min(count, 1 + getCount(index + 1, true));
        }

        return count;
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(cache, -1, sizeof(cache));
        this->nums1 = nums1;
        this->nums2 = nums2;
        this->nums1.insert(this->nums1.begin(), -1);
        this->nums2.insert(this->nums2.begin(), -1);
        size = this->nums1.size();

        return getCount(1, false);
    }
};
