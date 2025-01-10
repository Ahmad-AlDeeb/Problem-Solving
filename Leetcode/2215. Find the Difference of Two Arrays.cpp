class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> uniqueNums1 = new HashSet<>();
        Set<Integer> uniqueNums2 = new HashSet<>();
        Set<Integer> common = new HashSet<>();
        
        for(var num1 : nums1) {
            uniqueNums1.add(num1);
        }
        for(var num2 : nums2) {
            uniqueNums2.add(num2);

            if(uniqueNums1.contains(num2)) {
                common.add(num2);
            }
        }

        List<Integer> answer1 = new ArrayList<>();
        List<Integer> answer2 = new ArrayList<>();
        for(var num1 : uniqueNums1) {
            if(!common.contains(num1)) {
                answer1.add(num1);
            }
        }
        for(var num2 : uniqueNums2) {
            if(!common.contains(num2)) {
                answer2.add(num2);
            }
        }

        return Arrays.asList(answer1, answer2);
    }
}
