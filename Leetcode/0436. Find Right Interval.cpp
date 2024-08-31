class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> starts(n); // start, index
        for(int i{}; i<n; i++) {
            starts[i] = {intervals[i][0], i};
        }
        sort(starts.begin(), starts.end());

        vector<int> rightIntervals(n, -1);
        for(int i{}; i<n; i++) {
            vector<int> current_end {intervals[i][1], 0};
            auto it = lower_bound(starts.begin(), starts.end(), current_end);
            if(it == starts.end()) {
                continue;
            }

            rightIntervals[i] = it->at(1);
        }
        return rightIntervals;
    }
};
