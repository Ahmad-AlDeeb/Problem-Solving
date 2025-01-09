class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.length() == 0) {
            return true;
        }
        if(t.length() == 0) {
            return false;
        }

        int sIdx = 0;
        for(int tIdx = 0; sIdx < s.length() && tIdx < t.length(); tIdx++) {
            if(s.charAt(sIdx) == t.charAt(tIdx)) {
                sIdx++;
            }
        }
        return sIdx == s.length();
    }
}
