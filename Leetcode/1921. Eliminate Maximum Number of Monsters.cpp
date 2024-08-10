class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> steps(n);
        for(int i{}; i<n; i++) {
            steps[i] = ceil(dist[i] / (double) speed[i]);
        }
        sort(steps.begin(), steps.end());

        for(int i{}; i<n; i++) {
            if(steps[i] <= i) {
                return i;
            }
        }
        return n;
    }
};
