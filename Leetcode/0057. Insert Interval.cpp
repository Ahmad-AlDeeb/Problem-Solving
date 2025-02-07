class Solution {
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals {intervals.front()};

        for(int i{1}; i < intervals.size(); ++i) {
            vector<int> &lastInterval = mergedIntervals.back();
            vector<int> curInterval = intervals[i];

            if(curInterval[0] <= lastInterval[1]) {
                if(curInterval[1] > lastInterval[1]) {
                    lastInterval[1] = curInterval[1];
                }
            }
            else {
                mergedIntervals.push_back(curInterval);
            }
        }

        return mergedIntervals;
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        return merge(intervals);
    }
};
