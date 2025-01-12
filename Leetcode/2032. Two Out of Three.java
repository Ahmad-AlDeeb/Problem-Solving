class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        Set<Integer> unique1 = new HashSet<>();
        Set<Integer> unique2 = new HashSet<>();
        Set<Integer> unique3 = new HashSet<>();
        Set<Integer> allUnique = new HashSet<>();

        for(var num : nums1) {
            unique1.add(num);
            allUnique.add(num);
        }
        for(var num : nums2) {
            unique2.add(num);
            allUnique.add(num);
        }
        for(var num : nums3) {
            unique3.add(num);
            allUnique.add(num);
        }

        List<Integer> answerList = new ArrayList<>();
        for(var unique : allUnique) {
            int existCount = 0;

            if(unique1.contains(unique)) {
                existCount++;
            }
            if(unique2.contains(unique)) {
                existCount++;
            }
            if(unique3.contains(unique)) {
                existCount++;
            }
            
            if(existCount > 1) {
                answerList.add(unique);
            }
        }
        return answerList;
    }
}
