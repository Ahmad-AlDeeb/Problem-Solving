class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int minCost = 0;

        for(int i = cost.length - 1; i >= 0; i-=3) {
            minCost += cost[i];
            if(i != 0) {
                minCost += cost[i - 1];
            }
        }

        return minCost;
    }
}
