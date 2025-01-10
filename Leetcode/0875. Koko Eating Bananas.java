class Solution {
    private final int MAX_K = 1000000000;
    
    private boolean isValid(long speed, int[] piles, int h) {
        long hoursNeeded = 0;
        for(var pile : piles) {
            hoursNeeded += pile / speed;
            if(pile % speed != 0) {
                hoursNeeded++;
            }
        }
        return hoursNeeded <= h;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = MAX_K;
        int minSpeed = MAX_K;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid, piles, h)) {
                right = mid - 1;
                minSpeed = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return minSpeed;
    }
}
