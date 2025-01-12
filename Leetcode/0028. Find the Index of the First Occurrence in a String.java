class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.length() > haystack.length()) {
            return -1;
        }
        
        for(int i = 0; i < haystack.length(); ++i) {
            if(haystack.charAt(i) == needle.charAt(0)) {
                int haystackIdx = i;
                int needleIdx = 0;
                boolean isEqual = true;

                while(needleIdx < needle.length() && haystackIdx < haystack.length()) {
                    if(haystack.charAt(haystackIdx++) != needle.charAt(needleIdx++)) {
                        isEqual = false;
                        break;
                    }
                }

                if(isEqual && needleIdx == needle.length()) {
                    return i;
                }
            }
        }
        return -1;
    }
}
