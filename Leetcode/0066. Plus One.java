class Solution {
    public int[] plusOne(int[] digits) {
        for(int i = digits.length - 1; i >= 0; --i) {
            if(digits[i] != 9) {
                digits[i]++;
                break;
            }
            digits[i] = 0;
            
            if(i == 0) {
                int[] newDigits = new int[digits.length + 1];
                Arrays.fill(newDigits, 0);
                newDigits[0] = 1;
                return newDigits;
            }
        }
        return digits;
    }
}
