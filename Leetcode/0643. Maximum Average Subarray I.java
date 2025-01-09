class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double sum = 0.0;
        
        for(int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double maxAvg = sum / k;

        for(int l = 0, r = k; r < nums.length; ++l, ++r) {
            sum -= nums[l];
            sum += nums[r];
            maxAvg = Math.max(maxAvg, sum / k);
        }
        return maxAvg;
    }
}
