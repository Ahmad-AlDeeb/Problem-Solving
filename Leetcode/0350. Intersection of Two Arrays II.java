class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> countNums1 = new HashMap<>();
        List<Integer> intersectList = new ArrayList<>();

        for(var num : nums1) {
            countNums1.put(num, countNums1.getOrDefault(num, 0) + 1);
        }

        for(var num : nums2) {
            if(countNums1.getOrDefault(num, 0) > 0) {
                intersectList.add(num);
                countNums1.put(num, countNums1.get(num) - 1);
            }
        }

        return intersectList.stream().mapToInt(Integer::intValue).toArray();
    }
}
