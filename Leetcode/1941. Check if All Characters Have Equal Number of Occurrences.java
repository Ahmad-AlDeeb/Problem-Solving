class Solution {
    public boolean areOccurrencesEqual(String s) {
        Map<Character, Integer> chCount = new HashMap<>();
        for(var ch : s.toCharArray()) {
            chCount.put(ch, chCount.getOrDefault(ch, 0) + 1);
        }

        int count = chCount.get(s.charAt(0));
        for(var val: chCount.values()) {
            if(val != count) {
                return false;
            }
        }
        return true;
    }
}
