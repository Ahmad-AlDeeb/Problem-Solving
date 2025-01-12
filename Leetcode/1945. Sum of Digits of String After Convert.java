class Solution {
    private int getDigitsSum(int num) {
        int digitsSum = 0;
        while(num > 0) {
            digitsSum += (num % 10);
            num /= 10;
        }
        return digitsSum;
    }
    private int getCharVal(char c) {
        return c - 'a' + 1;
    }

    public int getLucky(String s, int k) {
        int sum = 0;
        for(var ch : s.toCharArray()) {
            sum += getDigitsSum(getCharVal(ch));
        }
        k--;

        while(k-- > 0) {
            sum = getDigitsSum(sum);
        }
        return sum;
    }
}
