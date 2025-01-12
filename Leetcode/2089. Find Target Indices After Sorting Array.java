class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        Arrays.sort(nums);
        List<Integer> numsList = new ArrayList<>();
        for(int i = 0; i < nums.length; ++i) {
            if(nums[i] == target) {
                numsList.add(i);
            }
        }
        return numsList;
    }
}
