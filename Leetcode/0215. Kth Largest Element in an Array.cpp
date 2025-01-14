////////////////// O(n log(n)) | O(1) //////////////////
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};


////////////////// O(n) | O(n) //////////////////
// Not my idea 
class Solution {
    int const MAX_VAL = 10000;

public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> posCount(MAX_VAL + 1);
        vector<int> negCount(MAX_VAL + 1);

        for(auto num : nums) {
            if(num >= 0) {
                posCount[num]++;
            }
            else {
                negCount[abs(num)]++;
            }
        }

        for(int num{MAX_VAL}; num >= 0; --num) {
            if(posCount[num] >= k) {
                return num;
            }
            else k -= posCount[num];
        }

        for(int num{1}; num <= MAX_VAL; ++num) {
            if(negCount[num] >= k) {
                return -num;
            }
            else k -= negCount[num];
        }

        return 0; // dump return to avoid compile error
    }
};
