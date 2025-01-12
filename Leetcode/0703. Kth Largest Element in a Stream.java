// I didn't get the idea to pass TLE and I copied the code to understand it
class KthLargest {
    private int k;
    private PriorityQueue<Integer> scores;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        scores = new PriorityQueue<>(k);

        for (int num : nums) {
            if (scores.size() < k) {
                scores.offer(num);
            } 
            else if (num > scores.peek()) {
                scores.offer(num);
                scores.poll();
            }
        }
    }

    public int add(int val) {
        if (scores.size() < k) {
            scores.offer(val);
        } 
        else if (val > scores.peek()) {
            scores.offer(val);
            scores.poll();
        }
        return scores.peek();
    }
}
