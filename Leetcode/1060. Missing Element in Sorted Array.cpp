class Solution {
public:
    /**
     * @param nums: An integer array
     * @param k: Find the kth missing number in nums
     * @return: nothing
     */
    int missingElement(vector<int> &nums, int k) {
        int n = nums.size();
        int answer{}, l{}, r{n-1};
        int count;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int missing_count = nums[mid] - nums[0] - mid;
            if(missing_count < k) {
                l = mid + 1;
                answer = mid;
                count = missing_count;
            }
            else {
                r = mid -1;
            }
        }

        k -= count;
        return nums[answer] + k;
    }
};
