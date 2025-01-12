class Solution {
    private int getTime(char from, char to) {
        int distance = Math.abs(from - to);
        int clockwise = Math.abs(from - 'z') + 1 + Math.abs('a' - to);
        int counterClockwise = Math.abs(from - 'a') + 1 + Math.abs('z' - to);

        return Math.min(distance, Math.min(clockwise, counterClockwise)) + 1;
    }
    public int minTimeToType(String word) {
        int minTime = getTime('a', word.charAt(0));
        System.out.println(minTime);

        for(int i = 0; i < word.length() - 1; ++i) {
            minTime += getTime(word.charAt(i), word.charAt(i + 1));
            System.out.println(minTime);
        }
        return minTime;
    }
}
