class Solution {
    boolean isVowel(char ch) {        
        Set<Character> vowels = new HashSet<>();
        Collections.addAll(vowels, 'a', 'e', 'i', 'o', 'u');
        ch = Character.toLowerCase(ch);
        return vowels.contains(ch);
    }
    
    public String reverseVowels(String s) {
        List<Integer> vowelsIndex = new ArrayList<>();
        for(int i = 0; i < s.length(); ++i) {
            if(isVowel(s.charAt(i))) {
                vowelsIndex.add(i);
            }
        }

        StringBuilder strBuilder = new StringBuilder(s);
        for(int l = 0, r = vowelsIndex.size() - 1; l < r; ++l, --r) {
            
            int leftIdx  = vowelsIndex.get(l);
            int rightIdx = vowelsIndex.get(r);

            char leftChar =  strBuilder.charAt(leftIdx);
            char rightChar = strBuilder.charAt(rightIdx);
            
            strBuilder.setCharAt(leftIdx, rightChar);
            strBuilder.setCharAt(rightIdx, leftChar);
        }
        return strBuilder.toString();
    }
}
