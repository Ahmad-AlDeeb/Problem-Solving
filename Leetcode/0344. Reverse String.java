class Solution {
    public void reverseString(char[] s) {
        for(int l = 0, r = s.length - 1; l <= r; ++l, --r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        }
    }
}
