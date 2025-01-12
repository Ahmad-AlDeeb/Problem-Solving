class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);

        Map<Integer, Integer> count = new HashMap<>();
        for(int i = sortedNums.length - k; i < sortedNums.length; ++i) {
            count.put(sortedNums[i], count.getOrDefault(sortedNums[i], 0) + 1);
        }

        List<Integer> maxSubList = new ArrayList<>();
        for(var num : nums) {
            if(count.getOrDefault(num, 0) > 0) {
                maxSubList.add(num);
                count.put(num, count.get(num) - 1);
            }
        }

        return maxSubList.stream().mapToInt(Integer::intValue).toArray();
    }
}
