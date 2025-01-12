class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int idxNum1 = nums1.length - 1;
        int idxNum2 = 0;
        
        for(; idxNum2 < nums2.length; --idxNum1, ++idxNum2) {
            nums1[idxNum1] = nums2[idxNum2];
        }
        Arrays.sort(nums1);
    }
}
