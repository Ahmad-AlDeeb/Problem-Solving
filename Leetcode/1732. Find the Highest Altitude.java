class Solution {
    public int largestAltitude(int[] gain) {
        int maxAltitude = Math.max(0, gain[0]);
        
        for(int i = 1; i < gain.length; ++i) {
            gain[i] += gain[i - 1];
            maxAltitude = Math.max(maxAltitude, gain[i]);
        }
        
        return maxAltitude;
    }
}
