class Solution {
    public int minimumDifference(int[] nums, int k) {
        int left = 0;
        int right = k - 1;
        
        Arrays.sort(nums);
        int minDiff = nums[right] - nums[left];

        while(right < nums.length) {
            minDiff = Math.min(minDiff, nums[right++] - nums[left++]);
        }
        return minDiff;
    }
}
