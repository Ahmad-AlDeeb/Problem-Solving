class Solution {
    public int countKDifference(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        for(var num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        int pairsCount = 0;
        for(var entry : count.entrySet()) {
            int target1 = entry.getKey() + k;
            int target2 = entry.getKey() - k;
            pairsCount += entry.getValue() * count.getOrDefault(target1, 0);
            pairsCount += entry.getValue() * count.getOrDefault(target2, 0);
        }
        return pairsCount / 2;
    }
}
